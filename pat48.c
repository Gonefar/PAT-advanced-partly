#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;

    return;
}

int qsortArray(int *array, int len)
{
    int i, last = 0;

    if( len <= 1 )
    {
        return 0;
    }

    swap(array, 0, rand()%len);
    for( i = 0; i < len; i++ )
    {
        if( array[i] < array[0] )
        {
            swap(array, ++last, i);
        }
    }

    swap(array, 0, last);
    qsortArray(array, last);
    qsortArray(array + last + 1, len - last - 1);
}

int findSolu(int *flag, int num, int pay)
{
    int i = 0, j = 0;
    int start, end, mid;

    start = 0;
    end = num - 1;          

    for( i = 1; i <= 500; i++ )
    {
        if( flag[i] > 0 && flag[pay-i] > 0 && i != pay - i )
        {
            printf("%d %d\n", i, pay-i);
            return 0;
        }
    }
    
    
    if( 0 == pay % 2 && flag[pay/2] >= 2 )
    {
        printf("%d %d\n", pay/2, pay/2);
        return 0;
    } 

    printf("No Solution\n");
    return 0;
}

int main()
{
    int num, pay, i, temp;
    int *coin = NULL;
    int flag[1001] = {0};

    scanf("%d%d", &num, &pay);
    //coin = (int *)malloc(sizeof(int) * num);

    for( i = 0; i < num; i++ )
    {
        scanf("%d", &temp);

        flag[temp]++; 
    }

    //qsortArray(coin, num);
    findSolu(flag, num, pay);

    return 0;
}

