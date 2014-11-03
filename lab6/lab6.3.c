#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 2
#define MAXFILA 8
#define LIMIT 64
#define M 30
#define N 20
static int increment=0;
static int fila[MAXFILA];
void* Produtor ()
{
	int j;
 	int i;
	for(i=0;i<LIMIT;i++)
	{
		for(j=0;j<MAXFILA;j++)
		{	
			if(fila[j]==0)
			{	printf("Produzi");
				fila[j]=j+M+N;
				break;
			}
		}
	sleep(1);
	}
	pthread_exit(NULL);
}
void* Consumidor()
{
int i;
int j;
	for(i=0;i<LIMIT;i++)
	{
		for(j=0;fila[j]<MAXFILA;j++)
		{	
			if(fila[j])
			{	
				printf("Consumi %d",fila[j]);
				fila[j]=0;
				break;
			
			}
		}
	sleep(2);
	}
	pthread_exit(NULL);
}
int main(void)
{
	pthread_t threads[NUM_THREADS];
	int t;
	for(t=0;t<MAXFILA;t++)
		fila[t]=0; //Zera tudo
	


	pthread_create(&threads[0], NULL, Produtor, (void *)0);
	pthread_create(&threads[1], NULL, Consumidor, (void *)1);

	for(t=0; t < NUM_THREADS; t++)
	pthread_join(threads[t],NULL);
/* espera pelo término de todas as threads*/
	return 0;
}
