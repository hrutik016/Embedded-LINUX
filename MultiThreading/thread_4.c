#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
int ret1, ret2;

void *fun(void *arg)
{
	unsigned long i=0;
	// return ID of thread in which it is invoked */
	pthread_t id = pthread_self();
	for(i=0;i<(0xFFFFFFFF);i++);
	/*Compare two threads, returns non-zero if equal else zero*/
	if(pthread_equal (id, tid[0]))
	{
		printf("\n First thread processing done \n");
		ret1=100;
		/*Terminates thread 1 and returns ret1 */
		pthread_exit(&ret1);
	}
	else
	{
		printf("\n Second thread processing done \n");
		ret2=200;
		/* Terminates thread 2 and return ret2 */
		pthread_exit(&ret2);
	}
	return NULL;
}

int main(void)
{
	int i = 0;
	int err;
	int *ptr[2];
	while(i<2)
	{
		err=pthread_create(&tid[i],NULL,&fun,NULL);
		/* Return non-zero value if thread is not created successfully */
		if(err!=0)
		{
			printf("\n can't create thread:[%s]", strerror(err));
		}
		else
		{
			printf("\n Thread created successfully \n");
		
		}
		i++;

	}
	/* waits for termination of thread and returns value to respective pointer */
	pthread_join(tid[0], (void**)&(ptr[0]));
	pthread_join(tid[1], (void**)&(ptr[1]));
	printf("\n return value from first thread is [%d]\n", *ptr[0]);
	printf("\n return value from first thread is [%d]\n", *ptr[1]);
}

