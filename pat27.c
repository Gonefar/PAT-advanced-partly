#include <stdio.h>

int convert(int num, int radix)
{
    int i = 0, digit;
    
    digit = num / radix;
    if( digit <= 9 )
    {
        printf("%d", digit);
    }
    else
    {
        printf("%c", digit - 10 + 'A');
    }
    
    digit = num % radix;
    if( digit <= 9 )
    {
        printf("%d", digit);
    }
    else
    {
        printf("%c", digit - 10 + 'A');
    }
    
    return 0;    
}

int main()
{
    int num, i;
    
    for( i = 0; i < 3; i++ )
    {
         scanf("%d", &num);
         
         if(i == 0)
         {
              printf("#");
         }
                 
         convert(num, 13);
    }
    
    return 0;
}
