#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuff
{
	long m_type;
	char msg_txt[10];
};

void main()
{
	struct msgbuff obj;
	int id;
	id=msgget(9,IPC_CREAT|0644);
	printf("%d\n", id);
	printf("Enter data to send..\n");
	scanf("%s",obj.msg_txt);
	obj.m_type=2;
	msgsnd(id,obj.msg_txt, strlen(obj.msg_txt)+1, 0);
	perror("msgsnd");
}



