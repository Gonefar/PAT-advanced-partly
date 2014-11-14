#include <stdio.h>
#include <string.h>

#define MAX 21

int getDigitInfo(int info[], char *num)
{
	int len = strlen(num), digit;

	memset(info, 0, sizeof(int) * 10);
	
	while( len != 0 )
	{
		digit = num[len-1] - '0';
		info[digit] += 1;
		len--;
	}
	
	return 0;
}

int douNum(char *initNum, char *dNum)
{
	int len = strlen(initNum);
	int add = 0, ret = 0, i = 0;
	
	if( initNum[0] - '0' >= 5 )
	{
		ret = 1;
	}
	
	while( len - i - 1 >= 0 )
	{
		dNum[i] = 2 * (initNum[len - i - 1] - '0') % 10 + add + '0';
		add = 2 * (initNum[len - i - 1] - '0') / 10;		
		i++;
	}
	
	if( add == 1 )
	{
		dNum[i] = '1';
		i++;
	}
	dNum[i] = '\0';
	
	return ret;
}

int isSame(int initNumInfo[], int dNumInfo[], int len)
{
	int i = 0;
	
	for( i = 0; i < len; i++ )
	{
		if( initNumInfo[i] != dNumInfo[i] )
		{
			return 1;
		}
	}
	
	return 0;
}

int reverseShowNum(char *num, int bits)
{
	int i = 0;
	
	for( i = 0; i < bits; i++ )
	{
		printf("%c", num[bits - i - 1]);
	}
	
	printf("\n");
	return 0;
}

int showNum(int *num, int bits)
{
	int i = 0;
	
	for( i = 0; i < bits; i++ )
	{
		printf("%d", num[i]);
	}
	
	printf("\n");
	return 0;
}

int procs(char *num)
{
	char dNum[MAX+1];
	int outputFlag = 0, initNumInfo[10], dNumInfo[10];
	
	outputFlag = douNum(num, dNum);
	getDigitInfo( initNumInfo, num );
	getDigitInfo( dNumInfo, dNum);
	
	//showNum(initNumInfo, 10);
	//showNum(dNumInfo, 10);
	if( isSame( initNumInfo, dNumInfo, 10) == 0 )
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
	if( outputFlag == 0 )
	{
		reverseShowNum(dNum, strlen(num));
	}
	else
	{
		reverseShowNum(dNum, strlen(num)+1);
	}
	
	return 0;
}

int main()
{
	char str[MAX];
	
	scanf("%s", str);
	procs(str);
	
	return 0;
}
