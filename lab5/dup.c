#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)

{

int fd; /* descritor a ser duplicado */

int retorno; /* valor de retorno de dup */

int retorno2; /* valor de retorno de dup2 */
printf("Dows ti works\n");

if ((fd=open("esteArquivo",O_RDWR|O_CREAT|O_TRUNC,0666)) == -1)

{

printf("Error open()\n");

return -1;

}

close(0); /* fechamento da entrada stdin */
printf("yep\n");
if ((retorno = dup(fd)) == -1)

{ /* duplicacao de stdin (menor descritor fechado) */

printf("Error dup()");

return -2;

}
printf("I think\n");

printf("Really\n");
printf ("valor de retorno de dup(): %d \n",retorno);

printf ("valor de retorno de dup2(): %d \n",retorno2);

return 0;

} 
