#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 4

void detab(char *);

int main(void)
{
	int c;
	unsigned int num_of_spaces;

	while ((c = getchar()) != EOF) {
		if ('\t' == c) {
			num_of_spaces = TABSTOP;

			while (num_of_spaces) {
				putchar('t');
				--num_of_spaces;
			}
		} else
			putchar(c);
	}

	return 0;
}

/* replace all the tabs with spaces in a string */
void detab(char s[])
{
	int i, k;
	int i_temp = 0;
	char temp[MAXLINE];

	/* copy s_array to temp */
	while ((temp[i_temp] = s[i_temp]) != '\0')
		++i_temp;

	i = k = 0;
	while (temp[i] != '\0' && temp[i] != '\n' && k < MAXLINE - 1) {
		if (temp[i] == '\t') {
			for (int x = k; k < x + TABSTOP; ++k)
				s[k] = ' ';
			++i;
		} else {
			s[k] = temp[i];
			++k;
			++i;
		}
	}

	if (temp[i] == '\n') {
		s[k] = temp[i];
		++k;
	}
	s[k] = '\0';
}
