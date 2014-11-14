#include <stdio.h>

int main()
{
    int num, i, desFloor, lastFloor = 0, sum = 0;
    
    scanf("%d", &num);
    
    for( i = 0; i < num; i++ )
    {
         scanf("%d", &desFloor);
         if( desFloor > lastFloor )
         {
             sum += 6 * (desFloor - lastFloor) + 5;
         }
         else if( desFloor < lastFloor )
         {
              sum += 4 * (lastFloor - desFloor) + 5;
         }
         else
         {
             sum += 0;
         }  
         
         lastFloor = desFloor;
         printf("i:%d sum:%d\n", i, sum);       
    }
    
    printf("%d\n", sum);
    return 0;
}
