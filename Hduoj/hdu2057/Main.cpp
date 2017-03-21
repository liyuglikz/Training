#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int i, j, k, len, word, a[1000];
    long long int num[2], sum, count;
    char cha[17] = "0123456789ABCDEF", str[2][1000];

    while (scanf("%s %s", str[0], str[1]) != EOF)
    {
        getchar();
        for (i = 0; i <= 1; ++i)
        {
            len = strlen(str[i]);
            if (str[i][0] == '-')
            {
                word = -1;
                str[i][0] = '0';
            }
            else if(str[i][0] == '+')
            {
                word = 1;
                str[i][0] = '0';
            }
            else
                word = 1;
            num[i] = 0;
            for (j = 0; j <= len - 1; ++j)
            {
                for (k = 0; k <= 15; ++k)
                {
                    if (str[i][j] == cha[k])count = k;
                }
                    num[i] += count * (long long )pow(16, len - 1- j);
            }
            num[i] *= word;
        }
        sum = num[0] + num[1];
        if (sum != 0)
        {
            word = 1;
            if (sum < 0)
            {
                word = -1;
                sum *= -1;
            }
            for (i = 0; sum > 0; ++i)
            {
                a[i] = sum % 16;
                sum /= 16;
            }
            len = i;
            if (word == -1)printf("-");
            for (i = len - 1; i >= 0; --i)
            {
                printf("%c", cha[a[i]]);
            }
            printf("\n");
        }
        else
            printf("0\n");
    }
    return 0;
}

