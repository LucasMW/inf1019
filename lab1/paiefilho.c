#include<stdio.h>
#include <unistd.h>
int main (void)
{

 printf("Eu sou o pai e meu pid é: %d\n", getpid());

 if(fork()!=0)
 
	printf("Eu sou o pai, esperando criar o filho. Meu pid: %d\n", getpid() );
 else

    printf("Eu sou o filho e meu pid é: %d\n" ,getpid() );

return 0;
}
