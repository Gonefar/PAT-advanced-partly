#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _node
{
    char account[11];
    char pd[11];
    int flag;
}node;

int changeStr(char *str)
{
    int i, len = strlen(str);
    int ret = 0;

    for( i = 0; i < len; i++ )
    {
        if( str[i] == '1' )
        {
            str[i] = '@';
            ret = 1;
        }
        else if( str[i] == '0' )
        {
            str[i] = '%';
            ret = 1;
        }
        else if( str[i] == 'l' )
        {
            str[i] = 'L';
            ret = 1;
        }
        else if( str[i] == 'O' )
        {
            str[i] = 'o';
            ret = 1;
        }
    }

    return ret;
}

int procs(node *accInfo, int len)
{
    int i = 0, sum = 0;

    for( i = 0; i < len; i++ )
    {
        if( changeStr((accInfo+i)->pd) == 1 )
        {
            (accInfo+i)->flag = 1;
            sum++;
        }
    }

    if( len == 1 && sum == 0 )
    {
        printf("There is 1 account and no account is modified\n");
    }
    else if( sum == 0 )
    {
        printf("There are %d accounts and no account is modified\n", len);
    }
    else
    {
        printf("%d\n", sum);
        for( i = 0; i < len; i++ )
        {
            if( (accInfo+i)->flag == 1 )
            {
                printf("%s %s\n", (accInfo+i)->account, (accInfo+i)->pd);
            }
        }
    }

    return 0;
}

int main()
{
    int i, n;
    node *accInfo = NULL;

    scanf("%d", &n);
    accInfo = (node *)malloc(sizeof(node) * n);
    memset(accInfo, 0, sizeof(node) * n);

    for( i = 0; i < n; i++ )
    {
        scanf("%s %s", (accInfo+i)->account, (accInfo+i)->pd);
    }

    procs(accInfo, n);
    return 0;
}

