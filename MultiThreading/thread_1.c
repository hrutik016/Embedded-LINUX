#include<stdio.h>
#include<string.h>
#include<pthread.h> // library for thread header files
#include<stdlib.h>
#include<unistd.h>

void *fun(void *arg)
{
	while(1)
	{
		printf("In Thread..\n");
		sleep(1);
	}
}

void *thread_1(void *arg)
{
	while(1)
	{
		printf("In Thread..1.\n");
		sleep(1);
	}
}

void main()
{
	pthread_t tid,tid1;
	pthread_create(&tid,NULL,fun,NULL);	
	pthread_create(&tid1,NULL,thread_1,NULL);		
	while(1)
	{
		printf("In main Thread\n");
		sleep(1);
	} 
}
