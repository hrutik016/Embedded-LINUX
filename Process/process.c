#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
	int id;
	
	if(fork())
	{
		while(1)
		{
			printf("in parent, PID=%d\n", getpid());
			sleep(5);
		}
	}
	else
	{
		while(1)
		{
			printf("in child, PID=%d\n", getpid());
			sleep(10);
		}
	}
}
