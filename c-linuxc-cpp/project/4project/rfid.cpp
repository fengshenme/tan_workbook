#include "rfid.h"

RFID::RFID()
{
}

RFID::~RFID()
{
}

int RFID::open_serial()
{
    int fd;

    fd = open("/dev/ttySAC1", O_RDWR | O_NOCTTY | O_NONBLOCK); //非阻塞的方式打开
    if (fd < 0) {
        printf("Open /dev/ttySAC1 fail!\n");
        return -1;
    }
    return fd;
}

int RFID::close_serial(int fd)
{
    if (close(fd)) {
        printf("%d %s :file close failed\n", __LINE__, __FILE__);
    }
    return 0;
}

/* 设置窗口参数:9600速率 */
void RFID::init_tty(int fd)
{
    //声明设置串口的结构体
    struct termios termios_new;

    //先清空该结构体
    bzero(&termios_new, sizeof(termios_new));

    //	cfmakeraw()设置终端属性，就是设置termios结构中的各个参数。
    cfmakeraw(&termios_new);

    //设置波特率
    //termios_new.c_cflag=(B9600);
    cfsetispeed(&termios_new, B9600);
    cfsetospeed(&termios_new, B9600);

    //CLOCAL和CREAD分别用于本地连接和接受使能，因此，首先要通过位掩码的方式激活这两个选项。
    termios_new.c_cflag |= CLOCAL | CREAD;

    //通过掩码设置数据位为8位
    termios_new.c_cflag &= ~CSIZE;
    termios_new.c_cflag |= CS8;

    //设置无奇偶校验
    termios_new.c_cflag &= ~PARENB;

    //一位停止位
    termios_new.c_cflag &= ~CSTOPB;
    //tcflush(fd,TCIFLUSH);

    // 可设置接收字符和等待时间，无特殊要求可以将其设置为0
    termios_new.c_cc[VTIME] = 2;
    termios_new.c_cc[VMIN] = 1;

    // 用于清空输入/输出缓冲区
    tcflush(fd, TCIFLUSH);

    //完成配置后，可以使用以下函数激活串口设置
    tcsetattr(fd, TCSANOW, &termios_new);
}

/*计算校验和*/
unsigned char RFID::CalBCC(unsigned char* buf, int n)
{
    int i;
    unsigned char bcc = 0;
    for (i = 0; i < n; i++) {
        bcc ^= *(buf + i);
    }
    return (~bcc);
}

//发送A命令
int RFID::PiccRequest(int fd)
{
    unsigned char WBuf[128], RBuf[128];
    int ret, len = 0;
    fd_set rdfd;

    memset(WBuf, 0, 128); //数组清空
    memset(RBuf, 0, 128);

    WBuf[0] = 0x07; //帧长= 7 Byte
    WBuf[1] = 0x02; //包号= 0 , 命令类型
    WBuf[2] = 0x41; //命令= 'A'
    WBuf[3] = 0x01; //信息长度
    WBuf[4] = 0x52; //请求模式:  ALL=0x52
    WBuf[5] = CalBCC(WBuf, WBuf[0] - 2); //校验和
    WBuf[6] = 0x03; //结束标志

    while (1) {
        FD_ZERO(&rdfd);
        FD_SET(fd, &rdfd);
        tcflush(fd, TCIFLUSH);
        //把A命令发送给RFID读取模块
        write(fd, WBuf, 7);

        ret = select(fd + 1, &rdfd, NULL, NULL, &timeout); //监测文件描述符的变化
        switch (ret) {
        case -1:
            perror("select error\n");
            break;
        case 0: //超时
            len++; //3次请求超时后，退出该函数
            if (len == 3) {
                len = 0;
                return -1;
            }

            //printf("Request timed out.\n");
            break;
        default:
            usleep(10000); //微秒
            ret = read(fd, RBuf, 8);

            if (ret < 0) {
                printf("len = %d, m \n", ret);
                break;
            }

            //printf("RBuf[2]:%x\n", RBuf[2]);
            if (RBuf[2] == 0x00) //应答帧状态部分为0 则请求成功
            {
                return 0;
            }
            break;
        }

        usleep(100000);
    }

    return -1;
}

/*防碰撞，获取范围内最大ID*/
int RFID::PiccAnticoll(int fd)
{
    //printf("fd = %d\n", fd);

    unsigned char WBuf[128], RBuf[128];
    int ret = 1, len = 0;
    fd_set rdfd;

    memset(WBuf, 0, 128);
    memset(RBuf, 1, 128);

    WBuf[0] = 0x08; //帧长= 8 Byte
    WBuf[1] = 0x02; //包号= 0 , 命令类型= 0x01
    WBuf[2] = 0x42; //命令= 'B'
    WBuf[3] = 0x02; //信息长度= 2
    WBuf[4] = 0x93; //防碰撞0x93
    WBuf[5] = 0x00; //位计数0
    WBuf[6] = CalBCC(WBuf, WBuf[0] - 2); //校验和
    WBuf[7] = 0x03; //结束标志

    while (1) {

        tcflush(fd, TCIFLUSH);
        FD_ZERO(&rdfd);
        FD_SET(fd, &rdfd);

        write(fd, WBuf, 8);
        ret = select(fd + 1, &rdfd, NULL, NULL, &timeout);
        switch (ret) {
        case -1:
            perror("select error\n");
            len++;
            if (len == 10) {
                len = 0;
                return -1;
            }
            break;
        case 0:
            len++;
            if (len == 10) {
                len = 0;
                return -1;
            }
            perror("190:rfid:Timeout:");
            break;

        default:
            usleep(10000);
            ret = read(fd, RBuf, 10);
            if (ret < 0) {
                printf("ret = %d\n", ret);
                break;
            }
            if (RBuf[2] == 0x00) //应答帧状态部分为0 则获取ID 成功
            {
                cardid = (RBuf[7] << 24) | (RBuf[6] << 16) | (RBuf[5] << 8) | RBuf[4];

                return 0;
            }
        }
    }

    return -1;
}
