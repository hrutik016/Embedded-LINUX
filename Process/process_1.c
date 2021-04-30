#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
	if(fork())
	{
		while(1)
		{
			printf("in parent, PID=%d\n", getpid());
			sleep(10);
		}
	}
	else if(fork())
	{
		while(1)
		{
			printf("in child_1, PID=%d\n", getpid());
			sleep(10);
		}
	}
	else if(fork())
	{
		while(1)
		{
			printf("in child_2, PID=%d\n", getpid());
			sleep(10);
		}
	}
	else
	{
		while(1)
		{
			printf("in child_3, PID=%d\n", getpid());
			sleep(10);
		}
	}
}
