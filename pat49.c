#include <stdio.h>

int getReptNum(int n, int num)
{
	int i = 0, sum = 0;
	
	for( i = 0; i < n; i++ )
	{
		sum = sum * 10 + num;
	}
	
	return sum;
}

int main()
{
	int i = 0, sum = 0, num, temp, tenExp = 1, bitNum;
	
	scanf("%d", &num);
	
	temp = num;
	while( temp != 0 )
	{
		if( i == 0)
		{
			sum += num / 10 + (num % 10 == 0 ? 0 : 1);
		}
		else
		{
			bitNum = num - getReptNum(i, 9);
			sum += bitNum / (10*tenExp) * tenExp; 
			
			if( bitNum % (tenExp*10) < tenExp)
			{
				sum += bitNum % (tenExp*10);
			}
			else
			{
				sum += tenExp;
			}

		}
		
		i++;
		tenExp *= 10;
		temp /= 10;
	}

	
	printf("%d\n", sum);
	
	return 0;
}
