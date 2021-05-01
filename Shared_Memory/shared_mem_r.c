#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/shm.h>

main()
{
	char *read;
	int id, i;
	id=shmget(5, 50, IPC_CREAT|0644);
	read=shmat(id, 0, 0);
	for(i = 0; i <= 40; read++, i++)
	{
		printf("%C\n", *read);
		sleep(1);
	}
}

