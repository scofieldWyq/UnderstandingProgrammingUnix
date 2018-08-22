#include <stdio.h>
#include <stdlib.h>
#define PAGELEN 24
#define LINELEN 512

/* declearing */
void do_more(FILE *);
int see_more(FILE *);

int main(int ac, char *av[])
{
	FILE *fp;
	if (ac == 1)
		do_more(stdin);

	else
		while(--ac)
			if((fp = fopen(*++av, "r")) != NULL)
			{
				do_more(fp);
				fclose(fp);
			}
			
			else
				exit(0);
	return 0;
}

void do_more(FILE *fp)
{
	char line[PAGELEN];
	int see_more(FILE *), reply;
	int num_of_line = 0;
    FILE *fp_tty;

	fp_tty = fopen("/dev/tty", "r");
	if (fp_tty == NULL)
		exit(0);

	while(fgets(line, LINELEN, fp)) /* read more chars */
	{
		if (num_of_line == PAGELEN) /* is full screen */
		{
			reply = see_more(fp_tty);
			if (reply == 0)
				break;

			num_of_line -= reply; /* reset */
		}

		if(fputs(line, stdout) == EOF)
			exit(1);

		num_of_line ++;
	}
}

int see_more(FILE *fp_tty)
{
	int c;
	printf("\033[7m more? \033[m");

	while((c = getc(fp_tty)) != EOF)
	{
		if (c == 'q')
			return 0;
		if (c == ' ')
			return PAGELEN;
		if (c == '\n')
			return 1;
	}

	return 0;
}




