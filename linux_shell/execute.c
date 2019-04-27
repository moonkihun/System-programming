#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"


int execute(int ac, char *av[], int sourcefd, char *sourcefile, int destfd, char *destfile,
	BOOLEAN append, BOOLEAN backgrnd)
{
	int pid;


	if (ac == 0 || shellcmd(ac, av, sourcefd, destfd))
	{
		return 0;
	}

	
	pid = fork();

	switch (pid)
	{
		
		case ERROR : 
			fprintf(stderr, "Cannot create new process.\n");
			return 0;

		
		case 0 :     
			redirect(sourcefd, sourcefile, destfd, destfile, append, backgrnd);
			execvp(av[0], av);
			fprintf(stderr, "Cannot execute %s\n", av[0]);
			exit(0);

	
		default :
		
			if(sourcefd > 0 && close(sourcefd) == ERROR)
			{
				syserr("close sourcefd");
			}

		
			if(destfd > 1 && close(destfd) == ERROR)
			{
				syserr("close destfd");
			}

		
			if(backgrnd)
			{
				printf("%d\n", pid);
			}
			
			return pid;
	}
}
