#include <stdio.h>
#include <string.h>

#define MAXLEN 120

int showNum(int digit[], int len)
{
	int i = 0;
	
	for( i = 0; i < len; i++ )
	{
		if(i == 0)
		{
			printf("%d", digit[i]);
		}
		else
		{
			printf(" %d", digit[i]);
		}
	}
	
	printf("\n");
	return 0;
}

int reverseShowNum(int digit[], int len)
{
	int i = 0;
	
	for( i = 0; i < len; i++ )
	{
		if(i == 0)
		{
			printf("%d", digit[len - 1 - i]);
		}
		else
		{
			printf("%d", digit[len - 1 - i]);
		}
	}
	
	printf("\n");
	return 0;
}

int isPal(int digit[], int len)
{
	int i = 0;
	
	for( i = 0; i <= len/2; i++ )
	{
		if( digit[i] != digit[len - 1 - i] )
		{
			return 1;
		}
	}
	
	return 0;
}

long int getReverseValue(int digit[], int len)
{
	long int sum =  0;
	int i = 0;
	
	for( i = 0; i < len; i++ )
	{
		sum = sum * 10 + digit[i];
	}
	
	return sum;
}

int addWithReverse(int digit[], int *len)
{
	int temp[MAXLEN], i;
	int add = 0, tempDigit;
	
	for( i = 0; i < *len; i++ )
	{
		temp[i] = digit[*len - i - 1];
	}
	
	for( i = 0; i < *len; i++ )
	{
		tempDigit = digit[i];
		digit[i] = (tempDigit + temp[i] + add) % 10;
		add = (tempDigit + temp[i] + add) / 10;
	}
	
	if( 1 == add )
	{
		(*len)++;
		digit[i] = 1;
	}
		
	return 0;
}

int procs(long int num, long int times)
{
	int len = 0, i = 0, j = 0;
	long int reversValue = 0, temp = num, lastTemp = 0;
	int digit[MAXLEN], tempDigit[MAXLEN];

	while(temp != 0)
	{
		digit[i] = temp % 10;
		temp = temp / 10;
		i++;
		len++;
	}

	if( isPal(digit, len) == 0 )
	{
		reverseShowNum(digit, len);
		printf("0\n");
		return 0;
	}
						
	for( j = 0; j < times; j++ )
	{
		memcpy(tempDigit, digit, MAXLEN * sizeof(int));
		
		addWithReverse(digit, &len);

		//printf("%d:", j+1);
		//reverseShowNum(digit, len);	
			
		if( isPal(digit, len) == 0 )
		{
			reverseShowNum(digit, len);
			printf("%d\n", j+1);
			break;
		}			
		
		if( j == times - 1)
		{
			reverseShowNum(digit, len);
			printf("%d\n", j+1);
			break;
		}

	}

	return 0;
}

int main()
{
	long int num, times;
	
	scanf("%ld%ld", &num, &times);
	
	procs(num, times);
	return 0;
}
