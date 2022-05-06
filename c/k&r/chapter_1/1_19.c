#include <stdio.h>

#define MAXLINE 1000

int get_line(char *, int);
void reverse_str(char *, int);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		reverse_str(line, len - 1); /* with \n */
		printf("%s", line);
	}

	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

void reverse_str(char *str, int str_len)
{
	char temp;
	for (int i = 0; i < str_len / 2; ++i) {
		temp = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = temp;
	}
}
