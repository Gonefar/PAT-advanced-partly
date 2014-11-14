#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ISLEAF 1
#define NOTLEAF 2
#define INIT 0
#define MAX 110

typedef struct _node
{
    int selfID;
    int parentID;
    int nodeFlag;
    int level;
}node;

int getNodeLevel( node * list, node *subNode )
{
    int level;
    
    if( INIT == subNode->nodeFlag )
    {
        return 0;
    }

    if( subNode->level > 0 )
    {
        return subNode->level;
    }
    
    if( 1 == subNode->parentID)
    {
        level = 2;
    }
    else
    {
        level = getNodeLevel(list, list + subNode->parentID) + 1;
    }

    return level;
}

int main()
{
    node *list = (node *)malloc(sizeof(node) * MAX);
    int totalNum, nonLeafNum, i = 0, j = 0;
    int tempID, subID, tempNum, maxLevel;
    int level[MAX] = {0};

    memset(list, 0, sizeof(node) * MAX);
    scanf("%d%d", &totalNum, &nonLeafNum);

    if( 0 == nonLeafNum )
    {
        printf("1\n");
        return 0;
    }
    
    for( i = 0; i < nonLeafNum; i++ )
    {
        scanf("%d%d", &tempID, &tempNum);

        if( tempNum > 0 )
        {
            list[tempID].nodeFlag = NOTLEAF;
        }
        else
        {
            list[tempID].nodeFlag = ISLEAF;
        }
        
        list[tempID].selfID = tempID;

        if( 1 == tempID )
        {
            list[1].level = 1;
        }

        for( j = 0; j < tempNum; j++ )
        {
            scanf("%d", &subID);
            if( list[subID].nodeFlag == INIT )
            {
                list[subID].nodeFlag = ISLEAF;
            }
            
            list[subID].selfID = subID;
            list[subID].parentID = tempID; 
        }
    }

    for( i = 1; i < MAX; i++ )
    {
        list[i].level = getNodeLevel(list, list+i);
    }

    for( i = 0; i < MAX; i++ )
    {
        if( list[i].level > 0 )
        {
            if( list[i].level > maxLevel )
            {
                maxLevel = list[i].level;
            }

            if( list[i].nodeFlag == ISLEAF )
            {
                level[(list[i].level)] ++;
            }
            //printf("max lvl:%d, cur lvl:%d\n", maxLevel, list[i].level);
        }
    }

    for( i = 1; i <= maxLevel; i++ )
    {
        if( 1 == i )
        {
            printf("%d", level[i]);
        }
        else
        {
            printf(" %d", level[i]);
        }
    }
    printf("\n");
/*
    for( i = 1; i < MAX; i++ )
    {
        if( list[i].nodeFlag != INIT )
        {
            printf("i:%d node:%d parent:%d lvl:%d flag:%d\n", i, list[i].selfID, list[i].parentID, 
            list[i].level, list[i].nodeFlag);
        }
    }*/
    return 0;
}

