#include <stdio.h>
#include <string.h>

#define MAX 20
#define MAXNUM 10000

int isPrime(int num)
{
    int i = 2;
    if(num == 1)
    {
        return 1;
    }

    for(i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
        {
            return 1;
        }
    }

    return 0;
}

int getReverseValue(int num, int radix)
{
    char str[MAX];
    int sum = 0, i = 0, temp = num;
    //printf("init:%d ", num);
    memset(str, 0, sizeof(char) * MAX);
    while( temp != 0 )
    {
        str[i] = temp % radix + '0';
        //printf("%c", str[i]);
        temp = temp / radix;
        i++;
    }

    i = 0;
    while( str[i] != 0 )
    {
        sum = sum * radix + str[i] - '0';
        i++;
    }
    //printf(" reverse:%d\n", sum);
    return sum;
}

int isReversePrime(int num, int radix)
{  
    if(isPrime(num) != 0)
    {
        printf("No\n");
        return 1;
    }

    if(isPrime(getReverseValue(num,radix)) != 0)
    {
        printf("No\n");
        return 1;
    }
    else
    {
        printf("Yes\n");
        return 0;
    }
}

int main()
{
    int num[MAXNUM], radix[MAXNUM];
    int len = 0, i = 0;

    scanf("%d", &(num[i]));
    if(num[i] < 0)
    {
        return 0;
    }
    
    while( num[i] > 0 )
    {
        scanf("%d", &(radix[i]));
        i++;
        len++;
        scanf("%d", &(num[i]));
    }

    for(i = 0; i < len; i++)
    {
        isReversePrime(num[i], radix[i]);
    }

    return 0;
}

