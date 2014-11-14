#include <stdio.h>
#include <string.h>

int int2py(char ch)
{
    switch(ch)
    {
        case '0': 
            printf("ling");
            break;
        case '1':
            printf("yi");
            break;
        case '2':
            printf("er");
            break;
        case '3':
            printf("san");
            break;
        case '4':
            printf("si");
            break;
        case '5':
            printf("wu");
            break;
        case '6':
            printf("liu");
            break;
        case '7':
            printf("qi");
            break;
        case '8':
            printf("ba");
            break;
        case '9':
            printf("jiu");
            break;
    }
}

int readBlock(char *num, int start, int dnum, int lvl)
{
    char unit[4][8] = {" Qian", " Bai", " Shi", ""};
    char level[3][5] = {" Yi", " Wan", ""};
    int flag = 0;
    int eflag = 0;
    static int bflag  = 0;

    if( dnum == 0 )
    {
        return 0;
    }
        
    for( int i = 0; i < dnum; i++ )
    {
        if( num[i+start] == '0' && flag == 0 )
        {
            continue;
        }
        else
        {
            flag = 1;
        }

        if(num[i+start] == '0' )
        {
            eflag = 1;
        }
        else
        {
            if( eflag == 1 )
            {
                printf(" ling");
                eflag = 0;
            }

            if( bflag == 0 )
            {
                bflag = 1;
            }
            else
            {
                printf(" ");
            }
            
            int2py(num[i+start]);
            printf("%s", unit[i+4-dnum]);
        }
    }
    
    printf("%s", level[3-lvl]);
    return 0;
}

int isZeroBlock(char *num, int start, int dnum)
{
    for( int i = 0; i < dnum; i++ )
    {
        if( num[start+i] != '0' )
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    char unit[5][5] = {"Yi", "Wan", "Qian", "Bai", "Shi"};
    char num[12];
    int dnum = 0, flag = 0, count = 0, lvl = 0, res = 0, zflag = 0;

    scanf("%s", num);

    if( num[0] == '-' )
    {
        flag = 1;
        printf("Fu ");
    }

    dnum = strlen(num) - flag;
    res = dnum % 4;
    lvl = dnum / 4 + ((dnum % 4) > 0 ? 1 : 0);
    
    if(res == 0)
    {
        readBlock(num, flag, 4, lvl);
        zflag = 1;
    }
    else
    {
        readBlock(num, flag, res, lvl);
    }

    if( num[flag] == '0' )
    {
        printf("ling");
        return 0;
    }
    
    for( int i = lvl - 1; i > 0; i-- )
    {
        if( isZeroBlock(num, flag+res+(lvl-i-1+zflag)*4, 4) != 0 )
        {
            break;
        }

        if( 1 == i )
        {
            return 0;
        }
    }

    for( int i = lvl - 1; i > 0; i-- )
    {
        if( isZeroBlock(num, flag+res+(lvl-i-1+zflag)*4, 4) == 0 && i != 1 )
        {
            if( num[flag+res+4] != '0' )
            {
                printf(" ling");
            }

            continue;
        }
        else if(isZeroBlock(num, flag+res+(lvl-i-1+zflag)*4, 4) == 0 && i == 1)
        {
            return 0;
        }

        if( num[flag+res+(lvl-i-1+zflag)*4] == '0' )
        {
            printf(" ling");
        }

        if( num[flag+res+(lvl-i-1+zflag)*4] != '0' && lvl >= 2 && i == 1
            && num[flag+res+(lvl-i-1+zflag)*4-1] == '0' )
        {
            printf(" ling");
        }
        
        readBlock(num, flag+res+(lvl-i-1+zflag)*4, 4, i);
    }
    
    //printf("\n");
    return 0;
}

