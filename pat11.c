#include <stdio.h>
#define MAX 9
#define W 1
#define T 2
#define L 3
#define INT_MODE 1
#define FLOAT_MODE 2

int swap(void *a, void *b, int mode)
{
    int tempInt;
    float tempFloat;
    
    if( INT_MODE == mode )
    {
        tempInt = *((int *)a);
        *((int *)a) = *((int *)b);
        *((int *)b) = tempInt;
    }
    else
    {
        tempFloat = *((float *)a);
        *((float *)a) = *((float *)b);
        *((float *)b) = tempFloat;
    }
    
    return 0;
}

int swapInt(int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
    
    return 0;
}

int swapFloat(float *a, float *b)
{
    float temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
    
    return 0;
}

int bubbleSort(float *bet, int *info, int len)
{
    int i = 0, j = 0;
    
    for( i = 0; i < len; i++ )
    {
         for( j = 0; j < i; j++ )
         {
              if( bet[i] > bet[j] )
              {
                  swapFloat(&bet[i], &bet[j]);
                  swapInt(&info[i], &info[j]);
                  //swap( (void*)bet+i, (void*)bet+j, FLOAT_MODE );
                  //swap( (void*)info+i, (void*)info+j, INT_MODE );
              }
         }
    }
/*    
    for(i = 0; i < len; i++ )
    {
          printf("%f ", bet[i]);
    }
    printf("\n");*/
    return 0;
}

int output( float sum, int *info )
{
    int i = 0;
    float temp = sum;
    
    //printf("%f %d\n", temp *100, (int)(temp*100));
    if( (temp * 100 - (int)(temp*100) ) >= 0.5 )
    {
        temp = (int)(sum*100) + 1;
    }
    else
    {
        temp = temp * 100;
    }
    
    for( i = 0; i < 9; i += 3 )
    {
         if( info[i] == 1 )
         {
             printf("W ");
         }
         else if( info[i] == 2 )
         {
              printf("T ");
         }
         else if( info[i] == 3 )
         {
              printf("L ");
         }
    }
    
    printf("%.2f\n", temp / 100);
    
    return 0;
}

int main()
{
    int i = 0;
    float bet[MAX], sum;
    float gain = 0.65;
    int info[MAX];
    
    for( i = 0; i < MAX; i++ )
    {
         scanf("%f", bet+i);
         info[i] = i % 3 + 1;
    }
    
    bubbleSort(bet, info, 3);
    bubbleSort(bet+3, info+3, 3);
    bubbleSort(bet+6, info+6, 3);
    sum = (bet[0] * bet[3] * bet[6] * gain - 1) * 2;
    //printf("%f\n", sum);
    //printf("%.2f\n", sum);
    //printf("%f\n", 1.1*2.2*3.3);
    output(sum, info);
    
    
    return 0;
}



