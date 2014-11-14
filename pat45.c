#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _color
{
    int value;
    int fav;
}color;

int isColorFav(color *favColorArray, int len, int colorValue)
{
    int i = 0;

    for( i = 0; i < len; i++ )
    {
        if( colorValue == favColorArray[i].value )
        {
            return i;
        }
    }

    return -1;
}

int maxOfThree(int a, int b, int c)
{
    int max = a;

    if( max < b )
    {
        max = b;
    }

    if( max < c )
    {
        max = c;
    }

    return max;
}

int main()
{
    int favColorNum, inputColorArrayNum;
    int *favColorArray = NULL, *inputColorArray = NULL;
    int i = 0, j = 0, index = 0, colorValue, fav, len = 0, max = 0;
    //int **path = NULL;
    int path[201][10001], colorNum;

    scanf("%d", &colorNum);
    scanf("%d", &favColorNum);
    favColorArray = (int *)malloc( sizeof(int) * favColorNum );
    for( i = 0; i < favColorNum; i++ )
    {
        scanf("%d", favColorArray+i);
        //favColorArray[i].fav = i;
    }

    scanf("%d", &inputColorArrayNum);
    inputColorArray = (int *)malloc( sizeof(int) * inputColorArrayNum );

    for( i = 0; i <= favColorNum; i++ )
    {
        path[i][0] = 0;
    }

    for( j = 0; j <= inputColorArrayNum; j++ )
    {
        path[0][j] = 0;
    }
    
    for( i = 0; i < inputColorArrayNum; i++ )
    {
        scanf("%d", &colorValue);
        //if( (fav = isColorFav(favColorArray, favColorNum, colorValue)) >= 0 )
        //{
            //inputColorArray[index].value = colorValue;
            //inputColorArray[index].fav = fav;
            inputColorArray[i]= colorValue;
            //inputColorArray[i].fav = 0;            
            //index++;
        //}
    }

    for( i = 1; i <= favColorNum; i++ )
    {
        for( j = 1; j <= inputColorArrayNum; j++ )
        {
            if( favColorArray[i-1] == inputColorArray[j-1] )
            {
                path[i][j] = 1 + maxOfThree(path[i][j-1], path[i-1][j], path[i-1][j-1]);
            }
            else
            {
                path[i][j] = maxOfThree(path[i][j-1], path[i-1][j], 0);
            }

            if( path[i][j] > max )
            {
                max = path[i][j];
            }
        }
    }

    printf("%d\n", max);

    return 0;
    
}

