#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define SINGLE_INSERT 0
#define DOUBLE_INSERT 1

int insert(int *flag, int city1, int city2, int mode, int *insertNum, int *linkFlag)
{
    if( DOUBLE_INSERT == mode )
    {
        if( flag[city1-1] == 0 && flag[city2-1] == 0 )
        {
            flag[city1-1] = flag[city2-1] = *linkFlag;
            (*linkFlag)++;
            *insertNum += 2;
        }
        else if( flag[city1-1] == 0 )
        {
            flag[city1-1] = flag[city2-1];
            *insertNum += 1;
        }
        else if( flag[city2-1] == 0 )
        {
            flag[city2-1] = flag[city1-1];
            *insertNum += 1;
        }
    }
    else
    {
        if( flag[city1-1] == 0 )
        {
            flag[city1-1] = *linkFlag;
            (*linkFlag)++;
            *insertNum += 1;
        }
    }

    return 0;
}

int procs(int *bridge, int bridgeLen, int checkCity, int cityNum)
{
    int i = 0, insertNum = 0, len = 0, index = 0, linkFlag = 1, linkNum = 0;
    int record[1000];
    
    int *flag = (int *)malloc(sizeof(int) *cityNum);
    memset(flag, 0, sizeof(int) * cityNum);
    
    
    for( i = 0; i < bridgeLen; i++ )
    {
        if( bridge[2*i] == checkCity )
        {
            record[index] = bridge[2*i+1];
            index++;
            len++;
        }
        else if( bridge[2*i+1] == checkCity )
        {
            record[index] = bridge[2*i];
            index++;
            len++;
        }
        else
        {
            insert(flag, bridge[2*i], bridge[2*i+1], DOUBLE_INSERT, &insertNum, &linkFlag);            
        }
    }

    for( i = 0; i < len; i++ )
    {
        insert(flag, record[i], 0, SINGLE_INSERT, &insertNum, &linkFlag);
    }
    
    printf("%d\n", cityNum-1-insertNum+linkFlag-2);
    free(flag);
    
    return 0;
}

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}

int qsortBridge(int *bridge, int len)
{
    int i = 0, last = 0;
    int randNum;

    if( len <= 1 )
    {
        return 0;
    }
    
    randNum = rand() % len;
    swap(bridge, bridge+2*randNum);
    swap(bridge+1, bridge+2*randNum+1);
    
    for( i = 1; i < len; i++ )
    {
        if( bridge[2*i] < bridge[0] )
        {
            ++last;
            swap(bridge+2*i, bridge+2*last);
            swap(bridge+2*i+1, bridge+2*last+1);
        }
    }
    
    swap(bridge, bridge+2*last);
    swap(bridge+1, bridge+2*last+1);
    qsortBridge(bridge, last);
    qsortBridge(bridge+last+1, len-last-1);
    
    return 0;
}

int main()
{
    int n, m, k, i;
    int *bridge = NULL, *checkCity = NULL;
    
    scanf("%d%d%d", &n, &m, &k);
    bridge = (int *)malloc(sizeof(int) * 2 * m);
    checkCity = (int *)malloc(sizeof(int) * k);
    
    for( i = 0; i < m; i++ )
    {
        scanf("%d%d", bridge+2*i, bridge+2*i+1);
    }

    qsortBridge(bridge, m);
    for( i = 0; i < k; i++ )
    {
        scanf("%d", checkCity+i);
    }

    for( i = 0; i < k; i++ )
    {
        procs(bridge, m, checkCity[i], n);
    }

    free(bridge);
    free(checkCity);
    return 0;
}

