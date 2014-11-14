#include <stdio.h>
#define MAX 44

int shift(float *arr, int *len, int pos, int offset)
{
	int i = 0;
	
	for( i = pos; i < (*len)*2 - offset; i++ )
	{
		arr[i] = arr[i+offset];
	}
	
	*len -= offset / 2;
	return 0;
}

int procsOutput(float *arr, int *len)
{
	int i = 0, tempLen = *len;

	for( i = 0; i < tempLen; i++ )
	{
		if( arr[2*i+1] == 0.0 )
		{
			shift(arr, len, 2*i, 2);
		}
	}
	
	return 0;
}

int output(float *arr, int len)
{
	int i = 0;
	
	if(len == 0)
	{
		printf("0\n");
	}
	else
	{
		printf("%d", len);
		for( i = 0; i < 2*len; i++ )
	    {
	        if( i % 2 != 0 )
	        {
	            printf(" %.1f", arr[i]);
	        }
	        else
	        {
	            printf(" %.0f", arr[i]);
	        }
	    }
	    printf("\n");
	}
	
	return 0;
}

int add(float *a, int numa, float *b, int numb, float *sum, int *sumab)
{
    int i = 0, j = 0, flag = 0;
    int indexa = 0, indexb = 0, indexsum = 0;

    while( a[2*indexa+1] != 0 || b[2*indexb+1] != 0 )
    {
			
        if( a[2*indexa] > b[2*indexb] )
        {
            sum[2*indexsum] = a[2*indexa];
            sum[2*indexsum+1] = a[2*indexa+1];
            indexsum++;
            indexa++;
            (*sumab)++;
        }
        else if( a[2*indexa] == b[2*indexb] )
        {
            sum[2*indexsum] = a[2*indexa];
            sum[2*indexsum+1] = a[2*indexa+1] + b[2*indexb+1];
            indexsum++;
            indexa++;
            indexb++;
            (*sumab)++;
        }
        else
        {
            sum[2*indexsum] = b[2*indexb];
            sum[2*indexsum+1] = b[2*indexb+1];
            indexsum++;
            indexb++;
            (*sumab)++;
        }
    }
	
    return 0;
}

int main()
{
    int i = 0;
    float a[MAX/2] = {0}, b[MAX/2] = {0};
    float sum[MAX] = {0};
    int numa, numb, sumab = 0;

    scanf("%d", &numa);
    for( i = 0; i < 2*numa; i++ )
    {
        scanf("%f", &(a[i]));
    }
	
    scanf("%d", &numb);
    for( i = 0; i < 2*numb; i++ )
    {
        scanf("%f", &(b[i]));
    } 

    add(a, numa, b, numb, sum, &sumab);
    procsOutput(sum, &sumab);
    output(sum, sumab);



    return 0;
}

