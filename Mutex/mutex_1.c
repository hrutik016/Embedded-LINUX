#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t mlock=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mlock1=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mlock2=PTHREAD_MUTEX_INITIALIZER;

void *thread_1(void *arg)
{
	char ch;
	for(ch = 'a'; ch<='z'; ch++)
	{
		pthread_mutex_lock(&mlock1);
		printf("%c\n", ch);
		sleep(1);
		pthread_mutex_unlock(&mlock);
	}
}

void *thread_2(void *arg)
{
	int i;
	for(i = 0; i<26; i++)
	{
		pthread_mutex_lock(&mlock2);
		printf("%d\n", i);
		sleep(1);
		pthread_mutex_unlock(&mlock1);
	}
}

void main()
{
	pthread_t tid1[2];
	char ch;
	
	pthread_mutex_lock(&mlock2);
	pthread_mutex_lock(&mlock1);
	
	pthread_create(&tid1[0],NULL,thread_1,NULL);
	pthread_create(&tid1[1],NULL,thread_2,NULL);
	
	for(ch ='A'; ch<='Z'; ch++)
	{
		pthread_mutex_lock(&mlock);
		printf("%c\n", ch);
		sleep(1);		
		pthread_mutex_unlock(&mlock2);
	}
}
