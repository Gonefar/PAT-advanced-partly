#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 100000

int swap(int *list, int i, int j)
{
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

int inOrder(int *list, int num)
{
    int i = 0;

    for( i = 0; i < num; i++ )
    {
        if( list[i] != i )
        {
            return 1;
        }
    }

    return 0;
}

int findIndex(int *list, int num, int value)
{
    int i = 0;

    for( i = 0; i < num; i++ )
    {
        if( list[i] == value )
        {
            return i;
        }
    }
  
}

int findPos(int *list, int num)
{
    int i = 0;

    for( i = 0; i < num; i++ )
    {
        if( list[i] != i )
        {
            return i;
        }
    }

    return 0;
}

int getSwapNum(int *list, int num, int *zeroIndex)
{
    int i = 0, key0Index = 0, keyNIndex = 0;
    int ret = 0;

    if( 0 == inOrder( list, num) )
    {
        return 0;
    }

    key0Index = *zeroIndex;
  
    if( key0Index != 0 )
    {
        keyNIndex = findIndex(list, num, key0Index);
        //printf("swap a[%d]=%d a[%d]=%d\n", key0Index, list[key0Index], keyNIndex, list[keyNIndex]);        
        swap(list, key0Index, keyNIndex);
        *zeroIndex = keyNIndex;
    }
    else
    {
        keyNIndex = findPos(list, num);
        //printf("swap a[%d]=%d a[%d]=%d\n", key0Index, list[key0Index], keyNIndex, list[keyNIndex]);
        swap(list, key0Index, keyNIndex);
        *zeroIndex = keyNIndex;
    }

    return 1;
    
}

int main()
{
    int i = 0, ret = 0, sum = 0, total, zeroIndex = 0, num = 0;
    int *list = (int *)malloc(sizeof(int) * MAX);
    char ch;

    scanf("%d", &total);
    scanf("%c", &ch);

    while( ch != '\n' )
    {
    	scanf("%d", &(list[i]));
    	i++;
    	num++;
    	scanf("%c", &ch);
    }

    zeroIndex = findIndex(list, total, 0);

    for( i = 0; i <= num; i++ )
    {
        ret = getSwapNum( list, total, &zeroIndex);
        
        if( 0 == ret )
        {
            break;
        }
    }
    
    printf("%d\n", i);

    return 0;
}

