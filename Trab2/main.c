#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 16
#define DeathTime 5 //Todos os threads executam 5 vezes e morrem
#define MEM_FRAMES 16

int fisMemPaginas[MEM_FRAMES]; //Tem a identificacao das paginas que tao na memoria
int threadNames[NUM_THREADS];
int contadores[MEM_FRAMES];
typedef enum 
{ 
  Open,
  Closed
} Door;
Door LRU_Door;
int search(int * vector,int limit,int element)
{	int i;
	for(i=0;i<limit;i++)
		if(vector[i]==element)
			return i; //Found , return Access Index

	return -1; //Not Found	
}
int LRU (int rPage)
{	
	int i;
	int r;
	if(LRU_Door==Closed)
		return 0; //Closed
	LRU_Door=Closed; /* A porta deve ser fechada, LRU deve ser atomica */
	r=search(fisMemPaginas,MEM_FRAMES,rPage);
	if(r >= 0) //Found
	{
		/* Alterar Contadores
		 Marcar Esta Página como Recentemente usada */
	}
	else //Not Found
	{
		/* Page Fault Sequence */

	}
	LRU_Door=Open; /* Liberado */
	return 1; // LRU Executed

}


int NumberOfVirtualPages(int numThreads,int pagesPerThread )
{
return numThreads*pagesPerThread;
}

void* ThreadFunction ()
{
	int wsLimit =4; //4 page frames
	int virtualPages =8; //Numero de paginas que os threads usarao
 	int i,id,r;
 	id=search(threadNames,NUM_THREADS,(int)0); //Ache um Zero
 	if(id<0)
 		printf("Erro!\n");
 	threadNames[id]=(int)pthread_self();

	for(i=0;i<DeathTime;i++)
	{	
		printf("Thread %d (%d) Executando pela %da vez\n",id+1,threadNames[id],i+1);
		/*Execute Thread and Call LRU */
		printf("Call for LRU\n");
		r=LRU(8*id+i); //Acesse a página de numero 8 * id + i
		if(!r) //LRU Está ocupada
		{
			i--; //Nao conte esta iteracao
			usleep(5000); //tente logo após
			

		}
		else //Funcionou! Espere 5 segundos para a proxima requisicao
			sleep(5);
	}
	pthread_exit(NULL);
}

int main(void)
{
	
	pthread_t threads[NUM_THREADS];
	int t;
	
	/* General initializations */ 
	for(t=0;t<MEM_FRAMES;t++)
	{
	fisMemPaginas[t]=-1; //No Page
	}
	for(t=0;t<NUM_THREADS;t++);
	{
	threadNames[t]=0; //No Id
	}
	
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
