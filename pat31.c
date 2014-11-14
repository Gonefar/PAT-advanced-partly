#include <stdio.h>
#include <string.h>

int printBlank(int n)
{
	int i = 0;
	
	for( i = 0; i < n; i++ )
	{
		printf(" ");
	}
	
	return 0;
}

int procs(char *str)
{
	int len = strlen(str);
	int i = 0, j = 0;
	int times = len/3 + ((len%3==0)?0:1);
	
	for( i = 0; i < times; i++ )
	{
		if( i != times - 1 )
		{
			printf("%c", str[i]);
			if( len % 3 == 0 )
			{
                printBlank( len / 3 );
            }
			else
			{
				printBlank(len % 3 + len / 3 - 2);
			}

			printf("%c\n", str[len - 1 - i]);
		}
		else
		{
            if( len % 3 == 0 )
            {
    			for( j = 0; j < (len % 3 + len / 3 + 2); j++ )
    			{
    				printf("%c", str[j+times - 1]);
    			}                
            }
            else
            {
    			for( j = 0; j < (len % 3 + len / 3); j++ )
    			{
    				printf("%c", str[j+times - 1]);
    			}
            }
			printf("\n");
		}
	}
	
	return 0;
}

int main()
{
	int num;
	char str[90];
	
	scanf("%s", str);
	procs(str);
	
	return 0;
}
