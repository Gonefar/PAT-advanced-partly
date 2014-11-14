#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define LOCALATION_NUM 100
#define TESTEE_NUM 300

typedef struct _testee
{
    char id[14];
    int   score;
    int   final_rank;
    int   local_num;
    int   local_rank;
}testee;

void swap(testee *pList, int i, int j)
{
    testee temp;
    temp = pList[i];
    pList[i] = pList[j];
    pList[j] = temp;

    return;
}

int show_list(testee *pList, int start, int end)
{
    int i = 0;

    for( i = start; i <= end; i++ )
    {
        printf("%s %d %d %d\n", pList[i].id, pList[i].final_rank, pList[i].local_num, pList[i].local_rank);
    }

    return 0;
}

int testee_qsort(testee *pList, int start, int end)
{
    int flag = 0, last = 0, i = 0;

    if( start >= end )
    {
        return 0;
    }

    swap(pList, start, rand() % (end - start) + start);
    last = start;

    for( i = start+1; i <= end; i++ )
    {
        if(pList[start].score < pList[i].score
            || (pList[start].score == pList[i].score && strcmp(pList[start].id, pList[i].id) > 0) )
        {
            swap(pList, ++last, i);
        }
    }

    swap(pList, start , last);
    testee_qsort(pList, start, last);
    testee_qsort(pList, last+1, end);
    
}

int get_local_info(testee *pList, int start, int end, int local)
{
    int i = 0, last = start;

    (pList + start)->local_rank = 1;

    (pList + start)->local_num = local;
    
    for( i = start+1; i <= end; i++ )
    {
        (pList + i)->local_num = local;

        if( (pList + i)->score == (pList + last)->score )
        {
            (pList + i)->local_rank = (pList + last)->local_rank; 
        }
        else
        {
            (pList + i)->local_rank = i - start + 1;
        }

        last++;
    }

    return 0;
}

int get_global_info(testee *pList, int start, int end)
{
    int i = 0, last = start;

    (pList + start)->final_rank = 1;
    
    for( i = start+1; i <= end; i++ )
    {
        if( (pList + i)->score == (pList + last)->score )
        {
            (pList + i)->final_rank = (pList + last)->final_rank; 
        }
        else
        {
            (pList + i)->final_rank = i - start + 1;
        }

        last++;
    }

    return 0;
}

int main()
{
    int testee_num, localation_num, i, j, total_testee = 0;
    testee *testeeList = (testee *)malloc( sizeof(testee) * LOCALATION_NUM * TESTEE_NUM);

    scanf("%d", &localation_num);
    for( i = 1; i <= localation_num; i++ )
    {
        scanf("%d", &testee_num);
        for( j = 0; j < testee_num; j++ )
        {
            scanf("%s %d", (testeeList + total_testee + j)->id, &((testeeList + total_testee + j)->score));
        }

        testee_qsort(testeeList, total_testee, total_testee + testee_num - 1);
        get_local_info(testeeList, total_testee, total_testee + testee_num - 1, i);
        total_testee += testee_num;
    }

    testee_qsort(testeeList, 0, total_testee - 1);
    get_global_info(testeeList, 0, total_testee - 1);
    printf("%d\n", total_testee);
    show_list(testeeList, 0, total_testee - 1);
    return 0;
}

