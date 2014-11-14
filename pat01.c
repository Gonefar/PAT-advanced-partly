#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int outArr(char* arr, int len)
{
    int i = 0;
    
     for( i = 0; i < len; i++ )
     {
        printf("%c", arr[i]);
     }
     
     printf("\n");
     return 0;
}

int convertintToChar(int num, char *arr, int *len)
{
	int temp = num, i = 0, flag = 0;
	
	if( num < 0)
	{
		arr[*len] = '-';
		*len = 1;
		flag = 1;
		temp = abs(num);
	}

	if(temp == 0)
	{
		*len = 1;
		arr[0] = '0';
	}	
	while(temp != 0)
	{
		(*len)++;
		temp /= 10;
	}
	
	temp = abs(num);
	for(i = 0; i < (*len) - flag; i++)
	{
		arr[*len - i - 1] = temp % 10 + '0';
		temp /= 10;
	}

	return 0;
}


int output(char *arr, int len)
{
	int reaLen, i = 0, flag = 0, num = 0, tempFlag = 0;
	char out[12];
	
	if( arr[0] == '-' )
	{
		reaLen = len - 1;
		i++;
		tempFlag = 1;
	}

    //outArr(arr,len);
	for(i = 0; i < len - tempFlag; i++)
	{
		out[i+flag] = arr[len - 1 - i];
		num++;
		if( arr[0] == '-' )
		{
			if(num % 3 == 0 && len - 1 - i != 1)
			{
				flag++;
				out[i+flag] = ',';			
			}
		}
		else
		{
			if(num % 3 == 0 && len - 1 - i != 0)
			{
				flag++;
				out[i+flag] = ',';
			}
		}
	}

    //printf("flag:%d len:%d\n", flag, len);
    //outArr(out, flag+len);
	if( tempFlag != 0)
	{
		printf("-");
	}
	
	for(i = 0; i < len+flag-tempFlag; i++)
	{
		printf("%c", out[len+flag - tempFlag - i - 1]);
	}
	
	printf("\n");
	return 0;
}

int main() 
{
	int a, b, len =  0;
	char arr[10];
	
	scanf("%d%d", &a, &b);
    	 convertintToChar(a+b, arr, &len);
    	 output(arr, len);
    	 
    	 return 0;
}
