#include <stdio.h>

// Max input
#define MAXLINE 1000
#define NULL_TERMINATOR '\0'
#define NEW_LINE '\n'

// Boolean enum
enum Boolean {
	True = 1,
	False = (!True),
};

/** @brief Checks whether the current input is inside a comment.
 *  
 *  If the current input and the increment of it equals the string of the 
 *  start of a comment block, change the status to "comment mode". Comment mode
 *  ignores all input while this is true. If current input and its increment equals
 *  the string of the end of a comment block, change the status to "normal mode" and 
 *  add to 2 to the current offset to reference the char after the end comment block. 
 *  Normal mode accepts all input.
 *
 *  TODO: separate the offset option
 *
 *  @param c The pointer to the current input.
 *  @param current_status Int pointer to the current status input.
 *  @param current_offset Int pointer to the current offset.
 *  @return int Return TRUE if input is inside a comment, return FALSE otherwise.
 */
enum Boolean input_is_inside_comment_block(const char *c,
					   enum Boolean *current_status,
					   int *current_offset)
{
	const int comment_blk_start = *c == '/' && *(c + 1) == '*';
	const int comment_blk_end = *c == '*' && *(c + 1) == '/';

	if (comment_blk_start) {
		// the input is a comment
		*current_status = True;
	}

	if (*current_status && comment_blk_end) {
		*current_status = False;
		// offset to the address after the char '/'
		*current_offset += 2;
	}

	return *current_status;
}

/** @brief Offsets the current input to the end of line or to the char after the 
 *         end of a comment block. 
 *  
 *  @param cur The pointer to the current input.
 *  @param current_input_status Int pointer to the current status input.
 *  @return int Return the pointer address of either the end-of-line or the char after 
 *              comment.
 */
char *offset_to_address_outside_comment(char *cur,
					enum Boolean *current_input_status)
{
	char *c_start = cur;
	int offset = 0;

	// increment offset until either end of line or the comment block end is reached
	// TODO: separate the +2 offset when the current input is a comment block end
	while ((input_is_inside_comment_block(cur, current_input_status,
					      &offset)) &&
	       *cur != NULL_TERMINATOR) {
		++offset;
		++cur;
	}

	return c_start + offset;
}

/** @brief Removes any input inside a comment block.
 *  
 *  @param str The pointer to the line input.
 *  @return void
 */
void remove_comment(char str[])
{
	char *cur = &str[0];
	static enum Boolean input_is_a_comment = False;

	while (*cur != NULL_TERMINATOR) {
		if (*cur == '/' || *cur == '*') {
			// offset to the address of the char outside the comment or to '/0'
			cur = offset_to_address_outside_comment(
				cur, &input_is_a_comment);
		}

		if (!input_is_a_comment) {
			putchar(*cur);
		}

		cur++;
	}
}

/** @brief Get input from user.
 *
 *  @param str The output array.
 *  @param lim The input limit.
 *  @return int Length of the input line.
 */
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != NEW_LINE; ++i)
		s[i] = c;

	if (c == NEW_LINE) {
		s[i] = c;
		++i;
	}
	s[i] = NULL_TERMINATOR;

	return i;
}

/** @brief Main function.
 *  
 *  @param void
 *  @return int return 0
 */
int main(void)
{
	int len;
	char line[MAXLINE] = { 0 };

	while ((len = get_line(line, MAXLINE)) > 0) {
		remove_comment(line);
	}

	return 0;
}
