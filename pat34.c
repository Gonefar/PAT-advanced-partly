#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _link
{
    char name1[4];
    char name2[4];
    int time;
    int flag;
}link;

typedef struct _head
{
    int name;
    int time;
    int cluster_num;
}head;

int getHeads(link *pList, head *pHeadList, int num, int th)
{
    int headIndex = 0, i = 0, init = 0, cluster_num = 0, link_num = 0, key = 0, keyIndex = 0, max = 0;
    int cluster[26] = {0};
    int usersTotalTime[26] = {0};
    int totalTime = 0;

    for( i = 0; i < num; i++ )
    {
        if( 1 == pList[i].flag )
        {
            continue;
        }

        if( 0 == init || cluster[((pList[i].name1)[0]-'A')] == 1
            || cluster[((pList[i].name2)[0]-'A')] == 1 )
        {
            cluster[((pList[i].name1)[0]-'A')] = 1;
            cluster[((pList[i].name2)[0]-'A')] = 1;
            usersTotalTime[((pList[i].name1)[0]-'A')] += pList[i].time;
            usersTotalTime[((pList[i].name2)[0]-'A')] += pList[i].time;
            totalTime += pList[i].time;
            pList[i].flag = 1;
            init = 1;
            link_num++;
            key = ((pList[i].name2)[0]-'A');
            //printf("%s %s link:%d\n", pList[i].name1, pList[i].name2, link_num);
        }
    }

    for( i = 0; i < 26; i++ )
    {
        if( 1 == cluster[i] )
        {
            cluster_num++;
            //printf("cluster:%c\n", i+'A');
        }
    }

    //printf("cluster:%d %d<<<\n", cluster_num, totalTime);
    if( cluster_num > 2 && totalTime > th)
    {
        max = usersTotalTime[0];
        for( i = 1; i < 26; i++ )
        {
            if( usersTotalTime[i] > max )
            {
                max = usersTotalTime[i];
                keyIndex = i;
            }
        }

        pHeadList[keyIndex].time = max;
        pHeadList[keyIndex].name = keyIndex;
        pHeadList[keyIndex].cluster_num = cluster_num;
        //printf(">>>get cluster\n");        
    }

    return link_num;
}

int output(head *pheadList ,int len)
{
    int i = 0, headNum = 0;

    for( i = 0; i < len; i++ )
    {
        if( pheadList[i].time > 0 )
        {
            headNum++;
        }
    }

    printf("%d\n", headNum);
    for( i = 0; i < len; i++ )
    {
        if( pheadList[i].time > 0 )
        {
            printf("%c%c%c %d\n", i+'A', i+'A', i+'A', pheadList[i].cluster_num);
        }
    }

    return 0;
}

int main()
{
    int num, th, i, totalCheck = 0;
    int usersTotalTime[26] = {0};
    link *pList = NULL;
    head *pHeadList = (head *)malloc( sizeof(head) * 26 );

    memset(pHeadList, 0, sizeof(head) * 26);
    scanf("%d%d", &num, &th);
    pList = (link *)malloc( sizeof(link) * num );

    for( i = 0; i < num; i++ )
    {
        scanf("%s %s %d", pList[i].name1, pList[i].name2, &(pList[i].time));
        pList[i].flag = 0;
    }

    while( totalCheck < num )
    {
        totalCheck += getHeads( pList, pHeadList, num, th);
    }

    output(pHeadList, 26);
    return 0;
}

