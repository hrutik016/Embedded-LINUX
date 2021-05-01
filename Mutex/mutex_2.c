#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mlock, mlock1;
FILE *fp;

void *thread_1(void *arg)
{
	char ch;
	for(ch='a'; ch<='z';ch++)
	{
		pthread_mutex_lock(&mlock1);
		fprintf(fp, "%c", ch);
		pthread_mutex_unlock(&mlock);
	}
}

void main()
{
	pthread_t tid1;
	char ch;
	
	pthread_mutex_init(&mlock1,NULL);
	pthread_mutex_init(&mlock,NULL);
	
	pthread_mutex_lock(&mlock1);
	pthread_create(&tid1,NULL,thread_1,NULL);
	
	fp=fopen("data","W");
	
	for(ch='A'; ch<='Z'; ch++)
	{
		pthread_mutex_lock(&mlock);
		printf("%c", ch);
		pthread_mutex_unlock(&mlock1);
	}
}
