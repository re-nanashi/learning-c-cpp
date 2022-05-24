#include <stdio.h>

#define TRUE 1
#define FALSE !TRUE

#define MAXLINE 1000

/** @brief Get input from user.
 *
 *  @param str The output array.
 *  @param lim The input limit.
 *  @return int Length of the input line.
 */
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

/** @brief Prints the reverse of the string input.
 *
 *  @param void
 *  @return void
 */
int reverse_str_input(void)
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		reverse_str(line, len - 1); /* with \n */
		printf("%s", line);
	}

	return 0;
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
		if (' ' == c)
			space = TRUE;
		if (!space)
			putchar(c);
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

/** @brief Print the conversion table of celsius to fahr.
 *
 *  @param void
 *  @return void
 */
int print_celcius_fahr_conversion(void)
{
	float celsius, fahr;
	int lower = 0, upper = 300, step = 20;

	celsius = lower;
	while (celsius <= upper) {
		fahr = celsius * 9.0 / 5.0 + 32.0;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius += step;
	}

	return 0;
}

/** @brief Convert the fahr input to celsius.
 *
 *  @param void
 *  @return void
 */
float convert_fahr_to_celsius(const float fahr)
{
	int celsius;

	celsius = (5.0 / 9.0) * (fahr - 32.0);

	return celsius;
}

/** @brief Print the conversion table of fahr to celsius.
 *
 *  @param void
 *  @return void
 */
int print_fahr_celsius_conversion(void)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celsius = convert_fahr_to_celsius(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr += step;
	}

	return 0;
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

/** @brief Compare 3 inputs then return the highest input int.
 *
 *  @param input_1 First integer input.
 *  @param input_2 Second integer input.
 *  @param input_3 Third integer input.
 *  @return int The highest input
 */
int max(const int input_1, const int input_2, const int input_3)
{
	int max;

	if ((input_1 >= input_2) && (input_1 >= input_3)) {
		max = input_1;
	} else if ((input_2 >= input_1) && (input_2 >= input_3)) {
		max = input_2;
	} else {
		max = input_3;
	}

	return max;
}

/** @brief Print plot data using "*" symbol.
 *
 *  @param i Current max input data 
 *  @param data Data to print.
 *  @return void
 */
void print_plot_data(int i, int *data)
{
	if (i == *data) {
		printf("*\t");
		--(*data);
	} else
		printf(" \t");
}

/** @brief Get user input then print a histogram of 
 *         the frequency of the char input. 
 *
 *  @param void
 *  @return void
 */
int frequency_histogram(void)
{
	/* parse input */
	int c, n_white, n_other;
	int n_digit[10] = { 0 };

	n_white = n_other = 0;

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			++n_digit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++n_white;
		else
			++n_other;
	}

	int max_occurence, digit_highest = 0;
	for (int i = 0; i < 10; ++i) {
		if (n_digit[i] > digit_highest)
			digit_highest = n_digit[i];
	}

	max_occurence = max(digit_highest, n_white, n_other);
	if (max_occurence == 0) {
		printf("No input provided.\nClosing Program...\n");
		return 0;
	}

	for (int i = max_occurence; i > 0; --i) {
		printf("%d\t", i);

		for (int j = 0; j < 10; ++j) {
			print_plot_data(i, &n_digit[j]);
		}
		print_plot_data(i, &n_white);
		print_plot_data(i, &n_other);

		printf("\n");
	}

	printf("\t");
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", i);
	}
	printf("n_white\t");
	printf("n_other\n");

	return 0;
}

/** @brief Get user input then print a histogram of 
 *         the length of the char input. 
 *
 *  @param void
 *  @return void
 */
int length_histogram(void)
{
	int ch, index, ch_length, max_occurence, state;
	int words_len_array[10];

	ch_length = 0, max_occurence = 0;
	state = FALSE;

	for (index = 0; index < 10; ++index)
		words_len_array[index] = 0;

	while ((ch = getchar()) != EOF) {
		/* check if input is not a whitespace char */
		if (ch != ' ' && ch != '\n' && ch != '\t') {
			state = TRUE;
			++ch_length;
		} else if (state) {
			state = FALSE;

			if (ch_length >= 1 && ch_length <= 9)
				++words_len_array[ch_length - 1];
			else if (ch_length > 9)
				++words_len_array[9];

			ch_length = 0;
		}
	}

	/* get the highest number of occurrence */
	for (index = 0; index < 10; ++index) {
		if (words_len_array[index] > max_occurence)
			max_occurence = words_len_array[index];
	}

	if (max_occurence == 0) {
		printf("No input provided. Please try again.\n");
		return 0;
	}

	/* print the histogram. */
	for (int i = max_occurence; i > 0; --i) {
		/* print y axis, number of occurrence */
		printf("%d\t", i);

		for (int j = 0; j < 10; ++j) {
			if (i == words_len_array[j]) {
				printf("*\t");
				--words_len_array[j];
			} else
				printf(" \t");
		}

		printf("\n");
	}

	/* print x axis */
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", i);
	}
	printf(">10\n");

	return 0;
}

/** @brief Get user input then print input per line. 
 *
 *  @param void
 *  @return void
 */
int print_input_per_line(void)
{
	int c, state;

	state = FALSE;
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t') {
			putchar(c);
			state = TRUE;
		} else if (state) {
			putchar('\n');
			state = FALSE;
		}
	}

	return 0;
}

/** @brief Copy an array to another array.
 *
 *  @param from Array to be copied.
 *  @param to Output array.
 *  @return void
 */
void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}
