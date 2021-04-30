#include <stdio.h>
#include<signal.h>

void func(int n)
{
	static int count;
	count++;
	if(count < 5)
	{
		printf("process is still running.....");
	}
	else
	{
		signal(2, SIG_DFL);
	}	
}

void main()
{
	printf("hello... pid = %d\n",getpid());
	signal(2, func);
	while(1);
}


