#include <stdio.h>
#include <malloc.h>

int main()
{
    int m, n, i;
    int *pix = NULL;
    int ntimes = 0, out;

    scanf("%d%d", &m, &n);
    pix = (int *)malloc(sizeof(int) * m * n);

    for( i = 0; i < m * n; i++ )
    {
        scanf("%d", pix + i);
    }

    if( m * n == 1 )
    {
        printf("%d\n", pix[0]);
        return 0;
    }
    
    for( i = 0; i < m*n; i++ )
    {
        if( ntimes == 0 )
        {
            out = pix[i];
            ntimes = 1;
        }
        else
        {
            if( out == pix[i] )
            {
                ntimes++;
            }
            else
            {
                ntimes--;
            }
        }
    }

    printf("%d\n", out);
    return 0;
        
}




