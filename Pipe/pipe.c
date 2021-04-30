#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

void main()
{
	int p[2], q[2];
	/* Defining Pipe p*/
	pipe(p);
	/* Defining Pipe q*/
	pipe(q);
	
	/* fork system call is used to create parent and child process resp.*/
	
	if(fork())
	{
		/*This is a Parent Process*/
		char s1[10], s2[10];
		printf("String entered from parent...\n");
		scanf("%s", s1);
		
		/*writing to pipe*/
		write(p[1], s1, strlen(s1)+1);
		
		/*reading from pipe q*/
		read(q[0], s2, sizeof(s2));
		printf("string recieved from child=%s\n", s2);
	}
	else
	{
		/*This is child Process*/
		char str1[10], str2[10];
		
		/*reading from pipe p*/
		read(p[0], str2, sizeof(str2));
		printf("String entered from child...\n");
		scanf("%s", str1);
		
		/*writing to pipe q*/
		write(q[1], str1, strlen(str1)+1);
		printf("String recieved from parent=%s\n", str2);
	}		
}

