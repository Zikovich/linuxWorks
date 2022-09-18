#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void usage()
{
	printf ("*** Welcome to Ziko Femto Shell \n");
	printf ("use command  (exit) close the program \n");
        printf ("any other command will be echoed \n");
}

int main()
{
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;

	usage();
	
	while(1)
	{
           printf ("Please enter you command : ");	

           nread = getline(&line, &len, stdin);
   	   
	  if ((nread == EOF)||(line[0] == '\n'))
          {
 		 // nothing
	  }
	  else  if ( strcmp("exit\n",line) == 0 )
	  {
		break;
          }
          else
	  {		
		printf ("Your command: %s", line);
	  }
	}

	free(line);
	printf("Exit Ziko Femto Shell! See you again :) \n");

	return 0;
}
