#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX 100002

typedef struct _node
{
    int value;
    char add[6];
    char next[6];
    char data;
}node;

inline int getAddValue(char *str)
{
    int sum = 0, i;
    int len = strlen(str);
    
    if( str[0] == '-' )
    {
        return -1;
    }
    
    for( i = 0; i < len; i++ )
    {
        sum = sum * 10 + str[i] - '0';
    }
    
    return sum;
}

int checkSingle(node *allNode, int start, int num, int add1, int add2)
{
    node *cur = NULL, *temp = NULL;
    int pos, count = 0;
    
    //printf("Single Mode\n");
    cur = allNode + start;

    if( -1 == add1 || -1 == add2 )
    {
        printf("-1\n");
        return -1;
    }
    
    while( cur->value != 0 )
    {
        //printf("%s-%s-%d\n", cur->add, cur->next, cur->value);

        pos = getAddValue( cur->add );
	printf("%s %c %s %d\n", cur->add, cur->data, cur->next, cur->value);
        if( cur->value >= 2 )
        {
        	printf("%s\n", cur->next);
        	return 0;
        }
        
        if( pos == add1 || pos == add2 )
        {
            printf("%s\n", cur->add);
            return 0;
        }

        cur = allNode + pos;
    }

    printf("-1\n");
    return 0;
}

int main()
{
    int num, i, pos, add1, add2;
    int endFlag[2], index = 0;
    char startAdd1[6], startAdd2[6];
    node *allNode = NULL, temp;
    
    scanf("%s%s%d", startAdd1, startAdd2, &num);
    allNode = (node *)malloc(sizeof(node) * MAX);
    memset(allNode, 0, sizeof(node) * MAX );
    add1 = getAddValue(startAdd1);
    add2 = getAddValue(startAdd2);
    
    for( i = 0; i < num; i++ ) // nodes 0,1 are reserved for end node
    {
        scanf("%s %c%s", temp.add, &(temp.data), temp.next);
        pos = getAddValue(temp.next);
        
        if( ( temp.next )[0] == '-' )
        {
            endFlag[index] = MAX - 2 + index;
            memcpy(allNode+ MAX - 2 + index, &temp, sizeof(node));
            (allNode + MAX - 2 + index)->value = 1;
            //printf("Normal:%s-%s-%d\n", (allNode + pos + 1)->add, (allNode + pos + 1)->next, (allNode + pos + 1)->value);                        
            index++;
            continue;
        }
        
        if( (allNode + pos)->value == 0 )
        {
            memcpy(allNode+pos, &temp, sizeof(node));
            (allNode + pos)->value = 1;
            //printf("Normal:%s-%s-%d\n", (allNode + pos + 1)->add, (allNode + pos + 1)->next, (allNode + pos + 1)->value);            
        }
        else
        {
            //printf("\nAPPEAL:%s-%s-%d\n", (allNode + pos + 1)->add, (allNode + pos + 1)->next, (allNode + pos + 1)->value);
            if( strcmp((allNode + pos)->add, temp.add) != 0 )
            {
                (allNode + pos)->value += 1;
            }
        }
    }
    
    if( index == 0 )
    {
        printf("-1\n");
    }
    else if( index == 1 )
    {
        checkSingle(allNode, endFlag[0], num, add1, add2);
    }
    else if( index == 2 )
    {
        //checkDouble(allNode, 0,  1, num, add1, add2);
        if( strcmp( allNode[(endFlag[0])].add, allNode[(endFlag[1])].add) != 0
            || allNode[(endFlag[0])].data != allNode[(endFlag[1])].data )
        {
            printf("-1\n");
        }
        else
        {
            checkSingle(allNode, endFlag[0], num, add1, add2);
        }
    }
    
    return 0;
}

