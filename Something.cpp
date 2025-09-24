#include <stdio.h>
#include <math.h>

void dec(float a, float b, float c)
{
    float d = b * b - 4 * a * c;
    if (d > 0)
    {
        printf("%f\n", (-b + sqrtf(d)) / (2 * a));
        printf("%f\n", (-b - sqrtf(d)) / (2 * a));
    } else if (d == 0) {
        printf("%f\n", -b / (2 * a));
    } else {
        printf("%f + i%f\n", -b/(2 * a), sqrtf(fabsf(d))/(2 * a));
        printf("%f - i%f\n", -b/(2 * a), sqrtf(fabsf(d))/(2 * a));
    }
}

char check(float a, float b, float c)
{
    if (a == 0 & b == 0 & c != 0)
    {
        printf("None");
    }
    else if(a == 0 & b == 0 & c == 0)
    {
        printf("Any number");
    }
    else if (a == 0) {
        printf("%f\n", -c/b);
    } else {
        return 1;
    }
    return 0;
}

int some(void )
{
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    if (check(a, b, c) == 1)
    {
        dec(a, b, c);
    }

    return 0;
}
