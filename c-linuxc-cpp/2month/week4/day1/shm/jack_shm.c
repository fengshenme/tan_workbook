#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>	  /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <semaphore.h>

//jack: 负责将数据发送到共享内存上。

int main()
{

	//1. 申请key值。
	key_t key = ftok(".", 10);

	//2. 根据key值去申请id号。
	int shmid = shmget(key, 2048, IPC_CREAT | 0666);

	//3. 根据id号去映射一片内存空间。
	char *p = shmat(shmid, NULL, 0);

	int flag = 0;

	// 1.创建有名信号量 需要打开/创建的有名信号量的名字，必须以"/"开头    "/sem_test"
	sem_t *signal_val = sem_open("/sem_test", O_CREAT, 0777, flag);
	bzero(p, 2048);
	//4. 从键盘中获取数据，然后将数据存放在共享内存中
	while (1)
	{
		
		fgets(p, 2048, stdin);
		// 2. 进行输入数据时进行v操作
		if (sem_post(signal_val) == -1)
		{
			printf(" v operate failed\n");
		}

		if (strncmp(p, "quit\n", 5) == 0)
		{
			break;
		}
	}

	//5. 撤销映射
	shmdt(p);

	// 3.关闭有名信号量
	if (sem_close(signal_val) == -1)
	{
		perror("close signal failed \n");
	}


	return 0;
}
