#include <stdio.h>

#define MAXNUM 10
#define MAX 9223372036854775808LL
#define MIN -9223372036854775808LL
int main()
{
    int num, i;
    long long int a[MAXNUM], b[MAXNUM], c[MAXNUM];

    scanf("%d", &num);
    
    for(i = 0; i < num; i++)
    {
        scanf("%lld", &(a[i]));
        scanf("%lld", &(b[i]));
        scanf("%lld", &(c[i]));
    }

    for(i = 0; i < num; i++)
    {
        if( a[i] > 0 && b[i] > 0 && (MAX - a[i] < b[i]) )
        {
            printf("Case #%d: true\n", i+1);
            continue;
        }

        if( a[i] < 0 && b[i] < 0 && c[i] < 0 )
        {
            if( a[i] <= c[i] - b[i] )
        	{
			printf("Case #%d: false\n", i+1);
        		continue;           		
        	}
        	else
    		{
  			printf("Case #%d: true\n", i+1);
            		continue;   			
    		}
            
        }
        else if( a[i] < 0 && b[i] < 0 && c[i] >= 0 )
    	{
            printf("Case #%d: true\n", i+1);
            continue;   		
    	}

        if( a[i] + b[i] > c[i] )
        {
            printf("Case #%d: true\n", i+1);
        }
        else
        {
            printf("Case #%d: false\n", i+1);
        }
    }

    return 0;
}

