#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct info
{
       char id[16];
       char signIn[10];
       char signOut[10];
};

int comTime(char *time1, char *time2)
{
    int len = strlen(time1);
    int i = 0;
    
    for( i = 0; i < len; i++ )
    {
         if( time1[i] == time2[i] )
         {
             continue;
         }
         else if( time1[i] > time2[i] )
         {
             return 1;
         }
         else
         {
             return 0;
         }
    }
    
    return 2;
}

int procs(struct info* studInfo, int len)
{
    struct info *lockStud = NULL, *unlockStud = NULL;
    int i;
    
    unlockStud = lockStud = studInfo;
    
    for(i = 1; i < len; i++)
    {
          if( comTime(unlockStud->signIn, (studInfo+i)->signIn ) == 1 )
          {
              unlockStud = studInfo + i;
          }
          
          if( comTime(lockStud->signOut, (studInfo+i)->signOut ) == 0 )
          {
              lockStud = studInfo + i;
          }
    }
    
    printf("%s %s\n", unlockStud->id, lockStud->id);
    return 0;
}
       
int main()
{
    int idNum, i;
    struct info *studInfo = NULL;
    
    scanf("%d", &idNum);
    studInfo = ( struct info* )malloc(idNum * sizeof(struct info));
    
    for( i = 0; i < idNum; i++ )
    {
         scanf("%s", (studInfo+i)->id);
         scanf("%s", (studInfo+i)->signIn);
         scanf("%s", (studInfo+i)->signOut);
    }
    
    procs(studInfo, idNum);
    
    return 0;
}
