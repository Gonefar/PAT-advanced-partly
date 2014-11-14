#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct _st
{
    char id[7];
    int cgrade;
    int mgrade;
    int egrade;
    int agrade;
    
    int arank;
    int crank;
    int mrank;
    int erank;
}st;

int getRank( st *stud, int len )
{
    int i = 0, j = 0;
    
    for( i = 0; i < len; i++ )
    {
         for( j = 0; j < len; j++ )
         {
              if( (stud+i)->cgrade < (stud+j)->cgrade )
              {
                  (stud+i)->crank ++;
              }
              
              if( (stud+i)->mgrade < (stud+j)->mgrade )
              {
                  (stud+i)->mrank ++;
              }
              
              if( (stud+i)->egrade < (stud+j)->egrade )
              {
                  (stud+i)->erank ++;
              }
              
              if( (stud+i)->agrade < (stud+j)->agrade )
              {
                  (stud+i)->arank ++;
              }                                          
         }
    }
    
    return 0;
}

int output(st *stud, int flag)
{
    if( flag == 0 )
    {
        printf("N/A\n");
        return 0;
    }
    else
    {
        if(stud->arank <= stud->crank && stud->arank <= stud->mrank
           && stud->arank <= stud->erank)
        {
              printf("%d A\n", stud->arank+1);
        }
        else if(stud->crank <= stud->mrank && stud->crank <= stud->erank)
        {
             printf("%d C\n", stud->crank+1);
        }
        else if(stud->mrank <= stud->erank)
        {
             printf("%d M\n", stud->mrank+1);
        }
        else
        {
            printf("%d E\n", stud->erank+1);
        }
    }
    
    return 0;
}

int procs(st *stud, int len, char *checkID)
{
    int flag = 0, i;
    
    for( i = 0; i < len; i++ )
    {
         if( strcmp(checkID, (stud+i)->id) == 0 )
         {
             flag = 1;
             break;
         }
    }
    
    output(stud+i, flag);
    return 0;
}

int main()
{
    int n, m, i;
    st *stud = NULL;
    char checkID[2000][7];
    
    scanf("%d%d", &n, &m);
    stud = (st *)malloc( sizeof(st) * n );
    //checkID = (char *)malloc( sizeof(char) * m * 7);
    //memset(checkID, 0, sizeof(char) * m * 7);
    memset(stud, 0, sizeof(st) * n );
    
    for( i = 0; i < n; i++ )
    {
         scanf("%s%d%d%d", (stud+i)->id, &(stud+i)->cgrade, 
                           &(stud+i)->mgrade, &(stud+i)->egrade);
         (stud+i)->agrade = ((stud+i)->cgrade+(stud+i)->mgrade+(stud+i)->egrade)/3;
    }
    
    getRank(stud, n);
    
    for( i = 0; i < m; i++ )
    {
         scanf("%s", checkID[i]);
    }
    
     for( i = 0; i < m; i++ )
    {
         procs(stud, n, checkID[i]);
    }
       
    return 0;
}

