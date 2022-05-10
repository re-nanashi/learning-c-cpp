#include <stdio.h>

#define MAXLINE 1000
#define TABSIZE 4

void entab(char *);
int get_line(char *, int);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0)
		entab(line);

	return 0;
}

void print_tabs_or_spaces(int count, int input)
{
	for (int i = 0; i < count; ++i) {
		putchar(input);
	}
}

/** @brief Counts the number of spaces and prints 
 *         tab if approriate.
 *
 *  @param c The pointer address 
 *  @return void
 */
void count_blanks_and_output_tabs_and_spaces(char **c)
{
	int blank_count = 0;

	while (*(*c) == ' ') {
		blank_count++;
		++(*c);
	}
	int tab_count = blank_count / TABSIZE;
	int space_count = blank_count % TABSIZE;

	print_tabs_or_spaces(tab_count, 't');
	print_tabs_or_spaces(space_count, 's');
}

void entab(char str[])
{
	char *c = &str[0];
	while (*c != '\0') {
		if (*c == ' ') {
			count_blanks_and_output_tabs_and_spaces(&c);
		} else {
			putchar(*c);
			c++;
		}
	}
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
