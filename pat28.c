#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 100000
#define ID_SORT 1
#define NAME_SORT 2
#define GRADE_SORT 3

typedef struct _stud
{
    char id[7];
    char name[10];
    int grade;   
}stud;

int show_list(stud *pList, int start, int end)
{
    int i = 0;

    for( i = start; i <= end; i++ )
    {
        printf("%s %s %d\n", pList[i].id, pList[i].name, pList[i].grade);
    }

    return 0;
}

int swap(stud *pList, int i, int j)
{
    stud temp;

    temp = pList[i];
    pList[i] = pList[j];
    pList[j] = temp;

    return 0;
}

int list_qsort(stud *pList, int start, int end ,int choice)
{
    int i = 0, last = start;

    if( start >= end )
    {
        return;
    }

    swap(pList, start, rand() % (end - start) + start);
    for( i = start + 1; i <= end; i++ )
    {
        if( GRADE_SORT == choice )
        {
            if( pList[i].grade < pList[start].grade 
                || (pList[i].grade == pList[start].grade && strcmp(pList[i].name, pList[start].name) > 0 ))
            {
                swap(pList, ++last, i);
            }
        }
        else if( ID_SORT == choice )
        {
            if( strcmp(pList[i].id, pList[start].id) < 0 )
            {
                swap(pList, ++last, i);
            }
        }
        else if( NAME_SORT == choice )
        {
            if( strcmp(pList[i].name, pList[start].name) < 0 
                || ( strcmp(pList[i].name, pList[start].name) == 0 && strcmp(pList[i].id, pList[start].id) < 0 ))
            {
                swap(pList, ++last, i);
            }
        }
        else
        {
            printf("Error choice\n");
            return -1;
        }
    }

    swap(pList, start, last);
    list_qsort(pList, start, last, choice);
    list_qsort(pList, last+1, end, choice);
}

int main()
{
    int num, choice, i;
    stud *pList = NULL;
    
    scanf("%d%d", &num, &choice);

    pList = (stud *)malloc( sizeof(stud) * num );

    for( i = 0; i < num; i++ )
    {
        scanf("%s %s %d", pList[i].id, pList[i].name, &(pList[i].grade));
    }
    
    list_qsort(pList, 0, num-1, choice);
    show_list(pList, 0, num-1);
    
    return 0;
}
