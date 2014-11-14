#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX 110

int getNumAfterChop(char *fnum, char *numChop, int sigNum)
{
    int i, index = 0, start = 0;
    int len = strlen(fnum), dotPos = 0;
    char exp[10];
    
    numChop[0] = '0';
    numChop[1] = '.';
    index = 2;
    
    for( i = 0; i < len; i++ )
    {        
        if( fnum[i] == '.' )
        {
            dotPos = i;
        }        
    }

    if( fnum[0] == '0' )
    {
        for( i = 0; i < len; i++ )
        {
            if( fnum[i] >= '1' && fnum[i] <= '9' )
            {
                start = i;
                //printf("%c(%d--)", fnum[i], i);
                break;
            }
        }

        if( 0 != start )
        {
            for( i = start; i < len && ( i - start ) < sigNum; i++ )
            {
                numChop[i - start + 2] = fnum[i];
                //printf("%c(%d)", fnum[i], i);
            }
        }
        else
        {
            for( i = 0; i < (sigNum - 1); i++ )
            {
                numChop[2 + i] = '0';
            }            
        }

        if( sigNum > ( len - start))
        {
            for( i = 0; i < (sigNum - (len - start)); i++ )
            {
                numChop[len - start + 2 + i] = '0';
            }
        }

        numChop[2+sigNum] = '\0';

        if( start > 0 )
        {
            sprintf(exp, "*10^%d", 2-start);
        }
        else
        {
            //numChop[1+sigNum] = '\0';
            sprintf(exp, "*10^0");
        }
        strcat(numChop, exp);
    }
    else
    {
        for( i = 0; i < len && (index - 2) < sigNum; i++ )
        {
            if( fnum[i] != '.' )
            {
                numChop[index] = fnum[i];
                //printf("%c(%d)", numChop[index], index);
                index ++;
            }
        }

        start = index;
        if( (index - 2) < sigNum )
        {
            for( i = 0; i < (sigNum -(index - 2)); i++ )
            {
                numChop[start] = '0';
                start++;
            }
        }

        numChop[start] = '\0';

        if( 0 == dotPos )
        {
            dotPos = len;
        }
        
        sprintf(exp, "*10^%d", dotPos);
        strcat(numChop, exp);
    }
    
    
    return 0;
}

char *preString( char *fnum)
{
    int i = 0, dotPos = 0;
    int len = strlen(fnum);
    int offset = 0;

    for( i = 0; i < len; i++ )
    {        
        if( fnum[i] == '.' )
        {
            dotPos = i;
        }        
    }

    if( dotPos == 0 )
    {
        for( i = 0; i < len - 1; i++ )
        {
            if( fnum[i] == '0' )
            {
                offset++;
            }
            else
            {
                break;
            }
        }        
    }
    else
    {
        for( i = 0; i < len - 1; i++ )
        {
            if( fnum[i] == '0' && fnum[i+1] != '.')
            {
                offset++;
            }
            else
            {
                break;
            }
        }        
    }

    return fnum+offset;
}

int procs(char *fnum1, char *fnum2, int sigNum)
{
    char num1chop[MAX], num2chop[MAX];
    int i = 0;

    fnum1 = preString(fnum1);
    fnum2 = preString(fnum2);
    //printf("%s %s\n", fnum1, fnum2);
    getNumAfterChop(fnum1, num1chop, sigNum);
    getNumAfterChop(fnum2, num2chop, sigNum);
    
    if( 0 == strcmp(num1chop, num2chop) )
    {
        printf("YES %s\n", num1chop);
    }
    else
    {
        printf("NO %s %s\n", num1chop, num2chop);
    }

    return 0;
}

int main()
{
    char fnum1[MAX], fnum2[MAX];
    int sigNum;
    
    scanf("%d %s %s", &sigNum, fnum1, fnum2);
    
    procs(fnum1, fnum2, sigNum);
    
    return 0;
}
