#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX 1010

int isSymtr(char *str, int startPos, int len)
{
    int i;
    
    for( i = 0; i <= len/2; i++ )
    {
         if( str[i + startPos] != str[len + startPos - i - 1] )
         {
             return 1;
         }
    }
    
    return 0;
}

int procs(char *str, int len)
{
    int i = 0, j = 0;
    int maxlen = 1;
    
    for( i = 2; i <= len; i++ )
    {
         for( j = 0; j <= len - i; j++ )
         {
             if( isSymtr(str, j, i) == 0 )
             {
                 if( i > maxlen )
                 {
                     maxlen = i;
                 }
             } 
         }
    }
    
    printf("%d\n", maxlen);
    return 0;
}

int main()
{
    char *str = (char *)malloc(sizeof(char) * MAX);
    int i = 0, len = 0;
    
    scanf("%c", str+i);
    while( str[i] != '\n' )
    {
        i++;
        len++;
        scanf("%c", str+i);
        
    }
    
    procs(str, len);
    
    return 0;
    
}
