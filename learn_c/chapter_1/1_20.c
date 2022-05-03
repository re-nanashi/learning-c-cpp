#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 4

int get_line(char *, int);
void detab(char *);
void copy(char *, char *);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		detab(line);
		printf("%s", line);
	}

	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if ('\n' == c) {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

void detab(char s[])
{
	int i_temp = 0;
	int i, k;
	char temp[MAXLINE];

	while ((temp[i_temp] = s[i_temp]) != '\0')
		++i_temp;

	i = k = 0;
	while (temp[i] != '\0' && temp[i] != '\n' && k < MAXLINE - 1) {
		if (temp[i] == '\t') {
			for (int x = k; k < x + TABSTOP; ++k)
				s[k] = ' ';
			--k;
		} else
			s[k] = temp[i];
		++k;
		++i;
	}

	if (temp[i] == '\n') {
		s[k] = temp[i];
		++k;
	}
	s[k] = '\0';
}
