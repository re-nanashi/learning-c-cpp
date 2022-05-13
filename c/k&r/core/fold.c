#include <stdio.h>
#include <ctype.h>

#define LINELIMIT 5
#define MAXINPUT 1000

#define TRUE 1
#define FALSE 0

void fold(char *);
int get_line(char *, int);

int main(void)
{
	int len;
	char line[MAXINPUT];

	while ((len = get_line(line, MAXINPUT)) > 0) {
		fold(line);
	}

	return 0;
}

/** @brief Print the input count number of times.
 *  
 *  @param count The number of times the input to be printed.
 *  @param input The char input to print.
 *  @return void
 */
void print_input_mult(int count, int input)
{
	for (int i = 0; i < count; ++i) {
		putchar(input);
	}
}

/** @brief Offset the current_address to the next non-whitespace char.
 *  
 *  @param cur The current input string address.
 *  @return char Pointer to the next non-whitespace char.
 */
char *offset_to_non_wchar(char *current_address)
{
	while (*current_address != '\0' && isspace(*current_address)) {
		current_address++;
	}

	return current_address;
}

/** @brief Check if all input before the 
 *         designated limit is all whitespace.
 *  
 *  Check if the current character all up to the character
 *  before the limit is all whitespace. If so, print '\n'
 *  after the last non-whitespace char before the limit
 *  then return the pointer offsetted to the next non-whitespace
 *  char. Else, print the cur input then return the offsetted address. 
 *
 *  @param cur The current input string address.
 *  @param current_index The current index of the char inside a string.
 *  @return char Pointer to the next non-whitespace char.
 */
char *all_input_before_limit_is_wchar(char *cur, int *current_index)
{
	char *temp_curr = cur;
	int temp_current_index = *current_index;

	while (temp_current_index < LINELIMIT) {
		if (!isspace(*cur)) {
			// ASSUME: input only uses spaces
			// TODO: convert tabs into spaces to count line limit
			// print space until the next non-whitespace char.
			print_input_mult(temp_current_index - (*current_index),
					 ' ');
			*current_index = temp_current_index;

			return offset_to_non_wchar(cur);
		}

		++cur;
		++temp_current_index;
	}

	// If there is a limit, print newline
	print_input_mult(1, '\n');
	*current_index = 0;

	return offset_to_non_wchar(temp_curr);
}

/** @brief Fold long input lines into 
 *         two or more shorter lines.
 *
 *  @param str The input string
 *  @return void
 */
void fold(char str[])
{
	char *c = &str[0];
	int cur_char_index = 0;

	while (*c != '\0') {
		if (*c == ' ') {
			// offset to next non-whitespace char
			// print the char/s before the next non-whitespace char
			c = all_input_before_limit_is_wchar(c, &cur_char_index);
		} else if (cur_char_index == LINELIMIT && *c != '\n') {
			putchar('-');
			putchar('\n');
			cur_char_index = 0;
		} else {
			putchar(*c);
			cur_char_index++;
			c++;
		}
	}
}

/** @brief Get input from user.
 *
 *  @param str The output array.
 *  @param lim The input limit.
 *  @return int Length of the input line.
 */
int get_line(char str[], int lim)
{
	int ch, index;

	for (index = 0;
	     index < lim - 1 && (ch = getchar()) != EOF && ch != '\n';
	     ++index) {
		str[index] = ch;
	}

	if (ch == '\n') {
		str[index] = ch;
		index++;
	}
	str[index] = '\0';

	return index;
}
