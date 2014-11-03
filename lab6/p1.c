#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 2
#define M 30
#define N 20
void *PrintHello(void *threadid)
{
	printf("%d: Hello World!\n", threadid);
	/* do other things */
	pthread_exit(NULL);
	/*não é necessário*/
}
void* ContCrescente ()
{
 	int i;
	for(i=0;i<N;i++)
	{
		pritnf("Ordem Crescente: %d\n",i+1);
		sleep(2);
	}

}
void* ContDecrescente()
{
int i;
	for(i=M;i>0;i++)
	{
		pritnf("Ordem Crescente: %d\n",i);
		sleep(1);
	}
}
int main(void)
{
	pthread_t threads[NUM_THREADS];
	int t;
	for(t=0;t < NUM_THREADS;t++)
	{
	printf("Creating thread %d\n", t);
	pthread_create(&threads[t], NULL, PrintHello, (void *)t);
	}
	for(t=0; t < NUM_THREADS; t++)
	pthread_join(threads[t],NULL);
/* espera pelo término de todas as threads*/
return 0;
}
