#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXFACT 22
#define MAXPROD 240

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

int multOneElement(float *a , int numa, float *ele, int numb, float *des)
{
	int i = 0;	
	
	for( i = 0; i < numa; i++ )
	{
		des[2*i] = a[2*i] + ele[0];
		des[2*i+1] = a[2*i+1] * ele[1];
	}
	
	return 0;
}

int add(float *a, int numa, float *b, int numb, float *sum, int *sumab)
{
    int i = 0, j = 0, flag = 0;
    int indexa = 0, indexb = 0, indexsum = 0;
    *sumab = 0;
    
    while( a[2*indexa+1] != 0.0 || b[2*indexb+1] != 0.0 )
    {

        //printf("a:%d %.0f %.1f b:%d %.0f %.1f ", indexa, a[2*indexa], a[2*indexa+1], indexb, b[2*indexb], b[2*indexb+1]);	 		
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
        //printf("sum:%d %.0f %.1f\n", (indexsum-1), sum[2*(indexsum-1)], sum[2*indexsum - 1]);

    }
	
    return 0;
}

int mult(float *a, int numa, float *b, int numb, float *prod, int *prodNum)
{
	int i = 0, tempProdNum;
	float temp[MAXFACT] = {0}, tempProd[MAXPROD] = {0};

       memset(tempProd, 0, sizeof(float)*MAXPROD);
       memset(temp, 0, sizeof(float)*MAXFACT);
	
	for( i = 0; i < numa; i++ )
	{
		multOneElement(b, numb, a+2*i, 2, temp);
		//printf("one mult:\n");
		//output(temp, numb);
		add(tempProd, MAXPROD, temp, numb, prod, prodNum);

             //printf("add: len:%d\n", *prodNum);
             //output(prod, *prodNum);
		procsOutput(prod, prodNum);
		//printf("one product:\n");
		//output(prod, *prodNum);
		
		if( i != numa - 1 )
		{
			memset(tempProd, 0, sizeof(float) * MAXPROD);
			memcpy(tempProd, prod, sizeof(float) * MAXPROD);
			memset(prod, 0, sizeof(float) * MAXPROD);
                    memset(temp, 0, sizeof(float) * MAXFACT);
		}
	}
	
	return 0;
}

int main()
{
    int i = 0;
    float a[MAXFACT] = {0}, b[MAXFACT] = {0};
    float prod[MAXPROD] = {0};
    int numa, numb, prodNum = 0;

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

    mult(a, numa, b, numb, prod, &prodNum);
    output(prod, prodNum);

    return 0;
}

