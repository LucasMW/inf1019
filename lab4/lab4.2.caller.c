
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main (int argc, char** argv)
{
	int pid1;
	int pid2;
	
	//int i;
	if(argc!=1)
	{
		printf("Esse programa executa apenas os programas pre-configurados\n");
		return 1;
	}
	pid1 = fork();
	
	   if (pID == 0)                // child
	   {
	      // Code only executed by child process
	 			printf("Filho usa date\n");
			
	     execl("/bin/date",  "date", (char *) 0);
	    }
	    else if (pID < 0)            // failed to fork
	    {
	        printf("Fork não deu certo!\n");
	        exit(1);
	        // Throw exception
	    }
	    else                                   // parent
	    {
	      // Code only executed by parent process
	 			printf("/nPai usa ls -a/n");
				fflush(stdout);
				execl("/bin/ls",  "ls", "-a", (char *) 0);
	    }
	 
	    // Code executed by both parent and child.
	   
	  		printf("BOTH\n");
	
	
	//execl("/bin/ls", "/bin/ls", "-r", "-t", "-l", (char *) 0);


	return 0;
}
