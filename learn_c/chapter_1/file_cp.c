#include <stdio.h>

int main(void)
{
	int c;

	printf("%d", EOF);
	while ((c = getchar()) != EOF) {
		putchar(c);
	}

	return 0;
}
