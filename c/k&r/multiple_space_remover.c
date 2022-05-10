#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
	int blank; /* flag for checking if previous char is blank */
	int c;

	while ((c = getchar()) != EOF) {
		if (c != ' ')
			blank = FALSE;
		if (!blank)
			putchar(c);
		if (c == ' ')
			blank = TRUE;
	}

	return 0;
}
