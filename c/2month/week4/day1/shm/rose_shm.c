
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>	  /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <semaphore.h>

//rose: 负责1s打印一次共享内存上的数据
// 已知shm/里面jack与rose通信时，会发生数据践踏
//     要求你使用有名信号量的技术解决这个问题。提示： 有名信号量机制.jpg

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
	
	//4. 不断打印共享内存上的数据
	while (1)
	{
		
		if (sem_wait(signal_val) == -1) // 2.读取数据前进行p操作
		{
			perror("p operate failed! \n");
		}
		printf("from shm:%s", p);
		if (strncmp(p, "quit\n", 5) == 0)
		{
			break;
		}
		bzero(p, 2048);
	}

		// 3.关闭有名信号量
	if (sem_close(signal_val) == -1)
	{
		perror("close signal failed \n");
	}
		// 4.删除有名信号量
	if (sem_unlink("/sem_test") == -1)
	{
		perror("delete /sem_test(Named semaphore) failed \n");
	}

	//5. 撤销映射
	shmdt(p);

	//6. 删除共享内存的对象
	shmctl(shmid, IPC_RMID, NULL);



	return 0;
}