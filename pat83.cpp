#include <stdio.h>
#include <algorithm>

typedef struct _stud
{
    char name[11];
    char id[11];
    int grade;
}stud;

using namespace std;

int cmp(stud a, stud b)
{
    if( a.grade < b.grade )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int num, grade1, grade2;
    int flag = 0;

    scanf("%d", &num);
    stud *pstud = new stud [num];

    for( int i = 0; i < num; i++ )
    {
        scanf("%s%s%d", pstud[i].name, pstud[i].id, &(pstud[i].grade));
    }

    scanf("%d%d", &grade1, &grade2);
    sort(pstud, pstud+num, cmp);

    for( int i = 0; i < num; i++ )
    {
        if( pstud[i].grade >= grade1 && pstud[i].grade <= grade2 )
        {
            printf("%s %s\n", pstud[i].name, pstud[i].id);
            flag = 1;
        }
    }

    if( 0 == flag )
    {
        printf("NONE\n");
    }
    
    return 0;
}

