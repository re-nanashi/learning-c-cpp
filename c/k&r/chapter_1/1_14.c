#include <stdio.h>

int max(int *, int *, int *);

void print_plot_data(int, int *);

int main(void)
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

	max_occurence = max(&digit_highest, &n_white, &n_other);
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

int max(int *input_1, int *input_2, int *input_3)
{
	int max;
	if ((*input_1 >= *input_2) && (*input_1 >= *input_3))
		max = *input_1;
	else if ((*input_2 >= *input_1) && (*input_2 >= *input_3))
		max = *input_2;
	else
		max = *input_3;

	return max;
}

void print_plot_data(int i, int *data)
{
	if (i == *data) {
		printf("*\t");
		--(*data);
	} else
		printf(" \t");
}
