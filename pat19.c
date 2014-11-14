#include <stdio.h>

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
			printf(" %d", digit[len - 1 - i]);
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

int procs(int num, int base)
{
	int digit[32], len = 0, i = 0;
	int temp = num;
	
	if( temp == 0 )
	{
		printf("Yes\n0\n");
		return 0;
	}
	
	while(temp != 0)
	{
		digit[i] = temp % base;
		temp = temp / base;
		i++;
		len++;
	}
	
	if( isPal(digit, len) == 0 )
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
	reverseShowNum(digit, len);
	return 0;
}

int main()
{
	int num, base;
	
	scanf("%d%d", &num, &base);
	
	procs(num, base);
	return 0;
}