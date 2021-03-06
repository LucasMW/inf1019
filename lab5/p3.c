#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char** argv)
{
	int pid1;
	int pid2;
	int status;
	int fd[2];

const char textoTX[] = "JASPION";
char textoRX[sizeof textoTX];
	if (pipe(fd) < 0)
	{
		puts ("Erro ao abrir os pipes");
		exit (-1);
	}	
pid1 = fork();

	if (pid1 == 0)                // child
	{
	      // Code only executed by child process
	 			write(fd[1], textoTX, strlen(textoTX)+1); 
			printf("Filho escreve %s\n",textoTX);
			exit(0);
	}
	else if (pid1 < 0)            // failed to fork
  {
	        printf("Fork não deu certo!\n");
	        exit(1);
	        
	}
	else        // pid1 >0         // parent
	{
	      // Code only executed by parent process
			
		waitpid(pid1,&status,0); //espere o filho
		
		read(fd[0], textoRX, sizeof textoRX );
	 		printf("Pai le %s\n", textoRX);
	}
	 

close(fd[0]); close(fd[1]);

	return 0;
}
