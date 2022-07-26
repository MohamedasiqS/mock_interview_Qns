#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
sem_t sem;
int i=0;

void *odd(void *args)
{
	sem_wait(&sem);
	while(1)
	{
		if (i%2!=0)
		{
			printf ("odd %d\n",i);
			i++;
		}
		else
			sem_post (&sem);
			
	}
}

void *even (void *args)
{
	sem_wait(&sem);
	while(1)
	{
		if (i%2 == 0)
		{
			printf ("even %d\n",i);
			i++;
		}
		else
			sem_post (&sem);
	}
}

int main (void)
{
	pthread_t t[2];
	sem_init (&sem,0,1);
	int i;
	void *(*fptr[2])(void*) = {odd,even};
	for (i=0;i<2;i++)
	{
		if (pthread_create (&t[i],NULL,fptr[i],NULL))
		{
			perror ("thread creation failed");
			exit (1);
		}
	}
	for (i=0;i<2;i++)
	{
		if (pthread_join  (t[i],NULL))
		{
			perror ("Thread join failed");
			exit (1);
		}
	}
	sem_destroy (&sem);
	return 0;
}
