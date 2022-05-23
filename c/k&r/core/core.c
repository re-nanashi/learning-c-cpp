#include <stdio.h>

#define TRUE 1
#define FALSE !TRUE

/** @brief Returns the reverse of the string input.
 *
 *  @param str_input The input string.
 *  @param str_len The length of the string to reverse.
 *  @return void
 */
void reverse_str(char *str_input, int str_len)
{
	char temp = 0;
	for (int i = 0; i < str_len / 2; ++i) {
		temp = str_input[i];
		str_input[i] = str_input[str_len - i - 1];
		str_input[str_len - i - 1] = temp;
	}
}

/** @brief Remove adjacent whitespace characters from user input.
 *
 *  @param void
 *  @return void
 */
void input_wo_adjacent_spaces(void)
{
	int space; /* flag for checking if previous char is space */
	int c;

	while ((c = getchar()) != EOF) {
		if (' ' != c)
			space = FALSE;
		if (!space)
			putchar(c);
		if (' ' == c)
			space = TRUE;
	}
}

/** @brief Get input without whitespace chars from the user. 
 *
 *  @param s The string array to output.
 *  @param lim String limit.
 *  @return int The length of user input.
 */
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

/** @brief Count whitespace characters from input.
 *
 *  @param void
 *  @return void
 */
void count_whitespace_ch(void)
{
	int c, blanks, tabs, newlines;

	blanks = tabs = newlines = 0;

	while ((c = getchar()) != EOF) {
		if (' ' == c)
			++blanks;
		if ('\t' == c)
			++tabs;
		if ('\n' == c)
			++newlines;
	}

	printf("%d blanks %d tabs %d newlines", blanks, tabs, newlines);
}

/** @brief Print user input with unambigous characters.
 *
 *  @param void
 *  @return void
 */
void print_unambigous_wchar(void)
{
	int ch = 0;

	while ((ch = getchar()) != EOF) {
		if ('\t' == ch) {
			printf("\\t");
		} else if ('\b' == ch) {
			printf("\\b");
		} else if ('\\' == ch) {
			printf("\\\\");
		} else
			putchar(ch);
	}
}

/** @brief Print the EOF value.
 *
 *  @param void
 *  @return void
 */
void print_eof_value(void)
{
	printf("%d\n", EOF);
}
