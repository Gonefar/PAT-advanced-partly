#include <stdio.h>
#include <string.h>

int main()
{
    int dNum[33];
    int a, b, d, sum, i = 0, len = 0;

    scanf("%d%d%d", &a, &b, &d);
    sum = a + b;

    if( 0 == sum )
    {
        printf("0\n");
        return 0;
    }

    while( 0 != sum / d || 0 != sum % d )
    {
        dNum[i] = sum % d;
        sum /= d;
        i++;
        len++;
    }

    for( i = len - 1; i >= 0; i-- )
    {
        printf("%d", dNum[i]);
    }

    printf("\n");
    return 0;
}

