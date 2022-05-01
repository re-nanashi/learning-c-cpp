#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
	int ch, index, ch_length, max_occurence, state;
	int words_len_array[10];

	ch_length = 0, max_occurence = 0;
	state = OUT;

	for (index = 0; index < 10; ++index)
		words_len_array[index] = 0;

	while ((ch = getchar()) != EOF) {
		/* check if input is not a whitespace char */
		if (ch != ' ' && ch != '\n' && ch != '\t') {
			state = IN;
			++ch_length;
		} else if (state) {
			state = OUT;

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
