#include <iostream>
#include <vector>

using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

long int maxCommFract(long int a, long int b)
{
    long int pa = (a<0?-a:a), pb = (b<0?-b:b);
    long int small = min(pa,pb);
    long int large = max(pa,pb);
    long int ret = 1;

    for( long int i = 2; i <= small && i <= large / 2; i++ )
    {
        if( small % i == 0 && large % i == 0 )
        {
            ret = i;
        }
    }

    return ret;
}

int swap(long int *a, long int *b)
{
    long int tmp = *a;
    *a = *b;
    *b = tmp;
}

int gcd(long int a, long int b)
{
    if( a < b )
    {
        swap(&a, &b);
    }

    if( 0 == b )
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}

long int findCommDeno(long int deno[], long int num)
{
    long int commDeno = 0;
    
    if( num == 1 )
    {
        return deno[0];
    }

    commDeno = deno[0] * deno[1] / gcd(deno[0], deno[1]);
    for( long int i = 2; i < num; i++ )
    {
        commDeno = commDeno * deno[i] / gcd(commDeno, deno[i]);
    }
    
    return commDeno;
}

long int getTotalNumr(long int commDeno, long int deno[], long int numr[], long int num)
{
    long int numrSum = 0;

    for( long int i = 0; i < num; i++ )
    {
        numrSum += commDeno / deno[i] * numr[i];
    }

    return numrSum;
}

int main()
{
    long int num, integ = 0, fractNum = 0, commFract = 0;
    long int commDeno = 0, totalNumr = 0;

    scanf("%ld", &num);
    long int *numr = new long int [num], *deno = new long int [num];

    for( long int i = 0; i < num; i++ )
    {
        scanf("%ld/%ld", numr+i, deno+i);
    }

    commDeno = findCommDeno(deno, num);
    totalNumr = getTotalNumr(commDeno, deno, numr, num);
    integ = totalNumr / commDeno;
    fractNum = totalNumr % commDeno;
    commFract = gcd(commDeno, fractNum);

    commDeno /= commFract;
    fractNum /= commFract;

    if(integ == 0 && fractNum == 0)
    {
        printf("0\n");
    }
    else if( integ == 0 )
    {
        printf("%ld/%ld\n", fractNum, commDeno);
    }
    else if( fractNum == 0 )
    {
        printf("%ld\n", integ);
    }
    else
    {
        printf("%ld %ld/%ld\n", integ, fractNum, commDeno);
    }

    return 0;
}

