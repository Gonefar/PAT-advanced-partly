#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i = 0, num, betNum, singOrder = 0, index;
    int *number = NULL, *info = NULL, *order = NULL;
    struct timeval start, end;
    
    scanf("%d", &num);
    number = (int *)malloc(sizeof( int) * 10000);
    info = (int *)malloc(sizeof( int) * 10000);
    order = ( int *)malloc(sizeof( int) * 10000);
    //memset(number, 0, sizeof( int) * 10000);
    //memset(info, 0, sizeof( int) * 10000);
    //memset(order, 0, sizeof(int) * 10000);
    
    gettimeofday(&start, NULL);
    for( i = 0; i < num; i++ )
    {
         scanf("%d", &betNum);
         if(i == 0 )
         gettimeofday(&start, NULL);
	    if( number[betNum-1]  == 0 )
	    {
	        number[betNum-1] = betNum;
	        info[betNum-1] = 1;
	        order[singOrder] = betNum;
	        singOrder++;
	    }
	    else
	    {
	        info[betNum-1]++;
	    }
	    
    }

    for( i = 0; i < 10000; i++ )
    {
    	 index = order[i] - 1;
        if( info[ index ] == 1 )
        {
        	printf("%d\n", number[ index ], index);
        	return 0;
        }
    }
    gettimeofday(&end, NULL);
    printf("%d-%d\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);
    printf("None\n");
    return 0;
    
}
