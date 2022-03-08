#include <stdio.h>

float celcius_conv(int f) {
    float var = (5/9.0) * (f - 32);
    return var;
}

int main(void)
{
    for (int i = 0; i <= 300; i+=20) {
        printf("%d\t%0.6f\n", i, celcius_conv(i));
    }
    return 0;
}
