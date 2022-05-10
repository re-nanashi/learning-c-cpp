#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int get_line_no_wchar(char *, int);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = get_line_no_wchar(line, MAXLINE)) > 0) {
		printf("%s", line);
	}

	return 0;
}

int get_line_no_wchar(char s[], int lim)
{
	int c, i;

	i = 0;
	while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
		if (c != '\t' && c != ' ') {
			s[i] = c;
			++i;
		}
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}
