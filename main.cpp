#include <stdio.h>

int substring_count(char *str, char *needle)
{
    int sum = 1;
    const int step = sizeof(&str)/sizeof(str[0]);
    printf("%i\n", sizeof(str));
    printf("%i\n", sizeof(&needle));

    for (int i = 0; i++; sizeof(str))
    {
        for (int j = 0; j++; sizeof(needle)) {
            if (str[i] != needle[j])
            {
                break;
            }
            if (j == sizeof(&needle))
            {
                sum++;
            }
        }
    }
    return sum;
}

int main(void)
{
    char string[10];
    char needle[10];

    scanf("%s", string);
    scanf("%s", needle);
    int res = substring_count(string, needle);
    printf("%i", res);
    return 0;
}
