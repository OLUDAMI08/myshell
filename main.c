#include "main.h"

int main(int argc,char **argv)
{

        /* variables*/

        char *prompt = "(newshell) #";
        char *lineptr, *dup_lineptr, *token;
        size_t n = 0;
        ssize_t get_return;
        const char *delim = " \n";
        int num_token, i;

        /*create an infinite loop */

        while (1)
	{
        printf("%s", prompt);
        get_return = getline(&lineptr, &n, stdin);

        if (get_return == -1)
        {
                printf("shell exit\n");
                return (-1);
        }
        (void)argc;
        /* memory allocation*/
        dup_lineptr = malloc(sizeof(char) * get_return);
        if (dup_lineptr == NULL)
        {
                perror("no available memory");
                return(-1);
        }
        /* duplicate the lineptr*/
        strcpy(dup_lineptr, lineptr);

        /*getting the number of tokenized strings*/
        token = strtok(lineptr, delim);
        for(num_token = 0; token != NULL; num_token++)

        {
                //printf("%s\n", token);
                token = strtok(NULL, delim);
        }
        //printf("%d\n", num_token);

        /*copy tokenized string out*/
	argv = malloc(sizeof(char) * num_token);

        token = strtok(dup_lineptr, delim);
        for (i = 0; token != NULL; i++)
        {
		printf("%s\n", token);
                argv[i] = malloc(sizeof(char) * strlen(token));
                strcpy(argv[i], token);
                token = strtok(NULL, delim);
      
      	}
        argv[i] = NULL;
	execute(argv);

	}

	//execute(argv);
        /* free up allocated memory */
        free(lineptr);
	 free(dup_lineptr);
        return 0;
}
          
