#include <stdio.h>
#include <math.h>
#include <string.h>

#define PR 1e-1
#define MIN(a, b) (a)>(b)?(b):(a)
#define MAX(a, b) (a)>(b)?(a):(b)

int getCharValue(char ch)
{
    if( ch >= '0' && ch <= '9' )
    {
        return (int)(ch - 48);
    }
    else if( ch >= 'a' && ch <= 'z' )
    {
        return (int)(ch - 87);
    }
}

int checkRadix(long int radix, char *n, int len)
{
    int i = 0, digit = 0;

    for( i = 0; i < len; i++ )
    {
        digit = getCharValue(n[i]);
        if( radix <= digit)
        {
            return -1;
        }
    }

    return 0;
}

long int getValue(char coeff, long int radix, int pow)
{
    int i = 0;
    long int sum = getCharValue(coeff);

    //printf("coeff, radix, pow:%d %d %d\n", coeff, radix, pow);
    for( i = 0; i < pow; i++ )
    {
        sum *= radix;
    }

    return sum;
}

long int getNum(char *n, long int radix)
{
    int i = 0, len = strlen(n);
    long int sum = 0;

    if( checkRadix(radix, n, len) < 0 )
    {
        return -1;
    }
    
    for( i = 0; i < len; i++ )
    {
        sum = sum * radix + getCharValue(n[i]);
    }

    return sum;
}
long int getRoot(long int num, int n)
{
    double x, x0, f, f0;

    if( 0 == n )
    {
        return num;
    }
    
    x = 1;
    do
    {
        x0 = x;
         f = pow(x, n) - num;
         f0 = n * pow(x, n-1);
         x = x0 - f / f0;
    }while(fabs(x-x0) >= PR);

    return (long int)x;
}

int getProbeRdx(long int min, long int max, long int *startRdx, long int *endRdx, char *n)
{
    int len = strlen(n), i = 0;
    int keyVal = getCharValue(n[0]);

    *startRdx = getRoot( min / (keyVal+1), len - 1) - 35;
    *endRdx  = getRoot( max / keyVal, len - 1) + 5;

    return 0;
    
}

int findRadix(char *n, long int startRdx, long int endRdx, long int num)
{
    int len = strlen(n);
    long int start = startRdx, end = endRdx, mid = 0;
    
    while( start < end )
    {
        if( (getNum(n, start) > num && getNum(n, end) > num) 
            || (getNum(n, start) < num && getNum(n, end) < num) )
        {
            printf("Impossible\n");
            return 0;
        }        

        //printf("%d %d\n", start, end);
        if( num == getNum(n, start) && 0 == checkRadix(start, n, strlen(n)))
        {
            printf("%ld\n", start);
            return 0;
        }
        
        if( num == getNum(n, end) && 0 == checkRadix(end, n, strlen(n)))
        {
            printf("%ld\n", end);
            return 0;
        }

        if( 1 == (end - start) )
        {
            break;
        }

        mid = (start + end) / 2;
        //mid = MAX((start + end) / 2, start+1);
        if( getNum(n, mid) >= num && getNum(n, start) < num)
        {
            //printf("%d %d\n", start, end);
            end = mid;
            continue;
        }
        
        //mid = MIN((start + end) / 2, end-1);
        if( getNum(n, mid) <= num && getNum(n, end) > num)
        {
            //printf("%d %d\n", start, end);
            start = mid;
        }
        else
        {
            break;
        }

        
    }

    //printf("%d %d\n", start, end);
    if( num == getNum(n, start) && 0 == checkRadix(start, n, strlen(n)) )
    {
        printf("%ld\n", start);
        return 0;
    }
    
    if( num == getNum(n, end) && 0 == checkRadix(end, n, strlen(n)))
    {
        printf("%ld\n", end);
        return 0;
    }

    printf("Impossible\n");
    return 0;
}

int procs(char *n1, char *n2, int tag, long int radix)
{
    int len1 = strlen(n1), len2 = strlen(n2);
    long int min, max, num;
    int i = 0;
    long int startRdx, endRdx;
    char *temp = NULL;

    if( 1 == tag )
    {
        num = getNum(n1, radix);
        min = getValue(n1[0], radix, len1-1);
        max = getValue(n1[0]+1, radix, len1-1);
        getProbeRdx(min, max, &startRdx, &endRdx, n2);
        temp = n2;
    }
    else
    {
        num = getNum(n2, radix);
        min = getValue(n2[0], radix, len2-1);
        max = getValue(n2[0]+1, radix, len2-1); 
        getProbeRdx(min, max, &startRdx, &endRdx, n1);
        temp = n1;
    }

    if( 1 == strlen(temp) )
    {
        if( num == getCharValue(temp[0] ) )
        {
            printf("%ld\n", num+1);
            return 0;
        }
    }

    //printf("min:%ld, max:%ld\n", min, max);
    //printf("startRdx:%ld, endRdx:%ld\n", startRdx, endRdx);
    findRadix(temp, startRdx, endRdx, num);
    return 0;
    
}


int procsBak(char *n1, char *n2, int tag, long int radix)
{
    int len1 = strlen(n1), len2 = strlen(n2);
    long int min, max, num;
    int i = 0;
    long int startRdx, endRdx;
    char *temp = NULL;

    if( 1 == tag )
    {
        num = getNum(n1, radix);
        min = getValue(n1[0], radix, len1-1);
        max = getValue(n1[0]+1, radix, len1-1);
        getProbeRdx(min, max, &startRdx, &endRdx, n2);
        temp = n2;
    }
    else
    {
        num = getNum(n2, radix);
        min = getValue(n2[0], radix, len2-1);
        max = getValue(n2[0]+1, radix, len2-1); 
        getProbeRdx(min, max, &startRdx, &endRdx, n1);
        temp = n1;
    }

    if( 1 == strlen(temp) )
    {
        if( num == getCharValue(temp[0] ) )
        {
            printf("%ld\n", num+1);
            return 0;
        }
    }
    
    //printf("min:%ld, max:%ld\n", min, max);
    //printf("startRdx:%ld, endRdx:%ld\n", startRdx, endRdx);
    for( i = startRdx; i <= endRdx; i++ )
    {
        if( i > 0 && num == getNum(temp, i) && 0 == checkRadix(i, temp, strlen(temp)))
        {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("Impossible\n");
    return 0;
    
}

int main()
{
    char n1[12], n2[12];
    int tag;
    long int radix;

    scanf("%s%s%d%ld", n1, n2, &tag, &radix);
    //printf("%s %s %d %d\n", n1, n2, tag, radix);
    procs(n1, n2, tag, radix);
    
    return 0;
}

