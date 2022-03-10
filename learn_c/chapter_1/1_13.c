#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
	int c, i, c_len, max_occur;
	int state;
	int len_of_words[10];

	c_len = 0, max_occur = 0;
	state = OUT;

	for (i = 0; i < 10; ++i)
		len_of_words[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t') {
			++c_len;
			state = IN;
		} else if (state) {
			if (c_len) {
				if (c_len >= 10)
					++len_of_words[9];
				else
					++len_of_words[c_len - 1];
			}
			c_len = 0;
			state = OUT;
		}
	}

	/* Get the highest number of occurances. */
	for (i = 0; i < 10; ++i) {
		if (len_of_words[i] > max_occur)
			max_occur = len_of_words[i];
	}

	if (max_occur == 0) {
		printf("No input provided. Please try again.\n");
		return 0;
	}

	/* Print the histogram. */
	for (int y = max_occur; y > 0; --y) {
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

	for (int x = 0; x < 10; ++x)
		printf("%d\t", x);
	printf(">10\n");

	return 0;
}
