#include <stdio.h>
#define PAGELEN 24
#define LINELEN 512

/* declearing */
void do_more(FILE *);
int see_more();

int main(int ac, char *av[])
{
	FILE *fp;
	if (ac == 1)
		do_more(stdin);

	else
		while(--ac)
			if(fp = fopen(*++av, 'r') != NULL)
			{
				do_more(fp);
				fclose(fp);
			}
			
			else
				exit(0);
	return 0;
}
