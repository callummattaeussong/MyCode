#include "threads.h"


static int globalvariable = 0; 



void myfunction(int threadid,int numberoftimes) {
	
	int localvariable = 0;

	int x=0;
	
	while(x<numberoftimes) {
		globalvariable=globalvariable+threadid;
		localvariable++;
		printf("\nThis is %d th execution of thread %d with global var value %d\n", localvariable,threadid, globalvariable);	
		yield();
		x++;
	}

	return;
}

int main() {
	
	RunQ = (struct queue*) malloc(sizeof(struct queue));
	int a,b;
	
	scanf("%d,%d",&a,&b);
	int numberofthreads=a;
	int numberoftimes =b;
	InitQueue(RunQ);
	if(a>0)
	{
		for(int x = 0;x<numberofthreads;x++)
		{
			start_thread(&myfunction,x+1,numberoftimes);
		}
	}
	else
	{
		printf("No Threads");
	}
	run();
}