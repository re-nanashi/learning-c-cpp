#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
	int c, i, c_len, max_occur, state;
	int len_of_words[10];

	c_len = 0, max_occur = 0;
	state = OUT;
	for (i = 0; i < 10; ++i)
		len_of_words[i] = 0;

	while ((c = getchar()) != EOF) {
		/* check if input is not whitespace */
		if (c != ' ' && c != '\n' && c != '\t') {
			state = IN;
			++c_len;
		} else if (state) {
			state = OUT;

			if (c_len >= 1 && c_len <= 9)
				++len_of_words[c_len - 1];
			else if (c_len > 9)
				++len_of_words[9];

			c_len = 0;
		}
	}

	/* get the highest number of occurrence */
	for (i = 0; i < 10; ++i) {
		if (len_of_words[i] > max_occur)
			max_occur = len_of_words[i];
	}

	if (max_occur == 0) {
		printf("No input provided. Please try again.\n");
		return 0;
	}

	/* print the histogram. */
	for (int y = max_occur; y > 0; --y) {
		/* print y axis, number of occurrence */
		printf("%d\t", y);

		for (int x = 0; x < 10; ++x) {
			if (y == len_of_words[x]) {
				printf("*\t");
				--len_of_words[x];
			} else
				printf(" \t");
		}
		printf("\n");
	}

	/* print x axis, word lengths */
	for (int x = 0; x < 10; ++x)
		printf("%d\t", x);
	printf(">10\n");

	return 0;
}
