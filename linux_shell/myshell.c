#include <stdio.h>
#include "common.h"


int main()
{
	int pid, fd;
  printf("***************************************************\n");
  printf("*                                                 *\n");
  printf("*             Hello, Have a good day!             *\n");
  printf("*           - This is my simple shell -           *\n");
  printf("*                                                 *\n");
  printf("*            System Programming Homework          *\n");
  printf("*             Hanyang University, ERICA           *\n");
  printf("*              Software Engineerinng              *\n");
  printf("*              Moon Ki Hun(2017015641)            *\n");
  printf("*                                                 *\n");
  printf("***************************************************\n");
  printf("*                  Realize Command                *\n");
  printf("*     1.cd 2.ls 3.mkdir.4.rmdir 5.cat 6.cp 7.mv   *\n");
  printf("***************************************************\n");
  printf("*          Press exit to exit or q or quit        *\n");
  printf("***************************************************\n");
  printf(
"\n"
"\t\t\\\n"
"\t\t \\   \\_\\_    _/_/\n"
"\t\t  \\      \\__/\n"
"\t\t   \\     (oo)\\_______\n"
"\t\t    \\    (__)\\       )\\/\\\n"
"\t\t             ||----w |\n"
"\t\t             ||     ||\n");

	SYMBOL term;

	
	print_prompt();

	
	while (TRUE)
	{
		
		term = parse(&pid, FALSE, NULL);

		
		if (term != S_AMP && pid != 0)
		{

			waitfor(pid);
		}

		
		if (term == S_NL)
		{
			print_prompt();
		}

		
		for (fd=3; fd<MAXFD; fd++)
		{
			close(fd);
		}
	}
}
