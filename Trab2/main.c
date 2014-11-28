#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#define NUM_THREADS 16
#define DeathTime 5 //Todos os threads executam 5 vezes e morrem
#define MEM_FRAMES 16

void* ThreadFunction ()
{
	int wsLimit =4; //4 page frames
	int virtualPages =8; //Numero de paginas que os threads usarao
 	int i;
	for(i=0;i<DeathTime;i++)
	{	
		printf("Executando pela %da vez\n",i+1);
		/*Execute Thread and Call LRU */
		printf("Call for LRU\n");
		sleep(5);
	}
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t threads[NUM_THREADS];
	int t;
	
	/* Crie o Thread a cada 5 Segundos */
	for(t=0; t < NUM_THREADS; t++)
        {
	printf("Creating Thread %d\n",t+1); 
	pthread_create(&threads[t], NULL, ThreadFunction, (void *)t);
	sleep(5);
	}

	

	for(t=0; t < NUM_THREADS; t++)
	pthread_join(threads[t],NULL);
/* espera pelo término de todas as threads*/
	return 0;
}
