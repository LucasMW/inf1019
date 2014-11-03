#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 2
#define M 30
#define N 20
static int increment=0;
void* ContCrescente ()
{
 	int i;
	for(i=0;i<N;i++)
	{
		printf("Turn %d\tOrdem Crescente: %d\n",increment++,i+1);
		sleep(2);
	}
	pthread_exit(NULL);
}
void* ContDecrescente()
{
int i;
	for(i=M;i>0;i--)
	{
		printf("Turn %d\tOrdem Decrescente: %d\n",increment++,i);
		sleep(1);
	}
	pthread_exit(NULL);
}
int main(void)
{
	pthread_t threads[NUM_THREADS];
	int t;



	pthread_create(&threads[0], NULL, ContCrescente, (void *)0);
	pthread_create(&threads[1], NULL, ContDecrescente, (void *)1);

	for(t=0; t < NUM_THREADS; t++)
	pthread_join(threads[t],NULL);
/* espera pelo término de todas as threads*/
	return 0;
}
