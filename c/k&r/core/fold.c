#include <stdio.h>
#include <ctype.h>

#define LINELIMIT 5
#define MAXINPUT 1000

#define TRUE 1
#define FALSE 0

void fold(char *);
int get_line(char *, int);
void entab(char str[]);

int main(void)
{
	int len;
	char line[MAXINPUT];

	while ((len = get_line(line, MAXINPUT)) > 0) {
		fold(line);
	}

	return 0;
}

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
 *  char. Else, print the cur input then return the offsetted 
 *
 *  Offset: let's say there is current char, if all the next chars are all blank
 *  and there's no limit then OFFSET to the next non whitespace 
 *  ELSE IF the next chars are blanks and there is a limit then add '\n' to the increment
 *  of the last non whitespace char then offset to the next non whitespace char.
 *
 *
 *  @param cur The current input string address.
 *  @return char Pointer to the next non-whitespace char.
 *
 *  TODO: Fix proper offsetting of pointer address
 *        CONVERT TABS TO SPACES
 *
 */
char *all_input_before_limit_is_wchar(char *cur, int *current_index)
{
	int temp_current_index = *current_index;

	while (temp_current_index < LINELIMIT) {
		if (!isspace(*cur)) {
			// print space until the next non-whitespace char
			print_input_mult(*current_index - temp_current_index,
					 ' ');
			*current_index = temp_current_index;

			return offset_to_non_wchar(cur);
		}

		++temp_current_index;
	}
	// IF THERE IS A LIMIT
	print_input_mult(1, '\n');
	*current_index = 0;

	return offset_to_non_wchar(cur);
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
			/* offset to next  */
			c = all_input_before_limit_is_wchar(c, &cur_char_index);
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
