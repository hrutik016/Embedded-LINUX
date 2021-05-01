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
	char msg_txt[20];
};

void main()
{
	struct msgbuff obj;
	int id;
	id=msgget(9, 0644);
	printf("%d\n", id);
	obj.m_type=0;
	msgrcv(id, obj.msg_txt, sizeof(obj.msg_txt), obj.m_type, 0);
	perror("msgrcv");
	printf("%s\n", obj.msg_txt);
}

