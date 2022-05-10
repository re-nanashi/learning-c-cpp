#include <stdio.h>

float convert_fahr_to_celsius(float fahr);

int main(void)
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

float convert_fahr_to_celsius(float fahr)
{
	int celsius;

	celsius = (5.0 / 9.0) * (fahr - 32.0);

	return celsius;
}
