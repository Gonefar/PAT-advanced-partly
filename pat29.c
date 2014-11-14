#include <stdio.h>
#include <malloc.h>

int main()
{
    int num1, num2, i, arr1Index = 0, arr2Index = 0, arrMegerIndex = 0;
    long int *inArr1 = NULL, *inArr2 = NULL, temp;

    scanf("%d", &num1);
    inArr1 = (long int *)malloc(sizeof(long int) * num1);
    for( i = 0; i < num1; i++ )
    {
        scanf("%ld", inArr1+i);
        //printf("%d ", *(inArr1+i));
    }

    scanf("%d", &num2);
    inArr2 = (long int *)malloc(sizeof(long int) * num2);
    for( i = 0; i < num2; i++ )
    {
        scanf("%ld", inArr2+i);
    }

    while( arr1Index < num1 || arr2Index < num2 )
    {
        if( (arr1Index < num1 && arr2Index < num2 && inArr1[arr1Index] < inArr2[arr2Index] )
            || (arr2Index >= num2 && arr1Index < num1) )
        {
        	  temp = inArr1[arr1Index];
            arr1Index++;
            arrMegerIndex++;
        }
        else if( (arr2Index < num2 && arr1Index <num1&& inArr1[arr1Index] >= inArr2[arr2Index] )
            || (arr1Index >= num1 && arr2Index < num2) )
        {
        	  temp = inArr2[arr2Index];
            arr2Index++;
            arrMegerIndex++;
        }
        
        //printf("%d ", temp);
        if( (arrMegerIndex-1) == (num1 + num2 - 1) / 2 )
	   {
	   	 printf("%ld\n", temp);
	   	 break;
	   }
        //printf("%d ", temp);
        
    }

    return 0;
}

