#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>

pthread_t tid[2];

void *fun(void *arg)
{
	unsigned long i =0;
	/* returns ID of thread in which it is invoked */
	pthread_t id = pthread_self();
	/* Compare two threads, return non-zero if equal else zero */
	if(pthread_equal(id,tid[0]))
	{
		printf("\n First thread processing \n");
		
	}
	else if (pthread_equal(id, tid[1]))
	{
		printf("\n Second thread processing \n");
	}
	
	for(i=0; i<0xFFFFFFFF;i++);
	return NULL;
}

int main(void)
{
	int i =0;
	int err;
	
	while(i<2)
	{
		/*Returns non-zero value if thread is not created successfully*/
		err=pthread_create(&tid[i],NULL,&fun,NULL);
		if(err!=0)
		{
			printf("\ncan't create thread:  [%s]", strerror(err));
		}
		else
		{
			printf("\n Thread %d created successfully \n", i);
		}
		i++;
	}
	sleep(5);
	return 0;
}

