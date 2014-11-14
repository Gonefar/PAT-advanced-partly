#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int isInStr(char *str, int len, char ch)
{
}

int main()
{
    int asc[128] = {0}, i = 0, len = 0;
    char *str = (char *)malloc( sizeof(char) * 10001 );
    char *cmp = (char *)malloc( sizeof(char) * 10001 );

    /*scanf("%c", str+i);
    while( *(str+i) != '\n' )
    {
        i++;
        len++;
        scanf("%c", str+i);
    }*/
    gets(str);
    //len = strlen(str);
    
    i = 0;
    scanf("%c", cmp+i);
    while( *(cmp+i) != '\n' )
    {
        asc[(int)*(cmp+i)] = 1;
        i++;
        scanf("%c", cmp+i);
    }

    i = 0;
    for( i = 0; str[i] != '\0'; i++ )
    {
        if( asc[(int)*(str+i)] == 0 )
        {
            printf("%c", *(str+i));
        }
    }

    printf("\n");
    return 0;
}

