#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct _info
{
    char name[21];
    char time[15];
    char state[10];
}info;

int swap(info *bInfo, int i, int j)
{
    info temp;
    
    memcpy(&temp, bInfo+i, sizeof(info));
    memcpy(bInfo+i, bInfo+j, sizeof(info));
    memcpy(bInfo+j, &temp, sizeof(info));

    return 0;
}

int quick_info(info *bInfo, int start, int end)
{
    int last = 0, index = 0, i = 0;

    if( end <= start )
    {
        return 0;
    }

    last = start;
    swap(bInfo, start, start + rand() % (end - start));
    for( i = start + 1; i <= end; i++ )
    {
        if( strcmp(bInfo[start].name, bInfo[i].name) > 0 
        || ( strcmp(bInfo[start].name, bInfo[i].name) == 0 && strcmp(bInfo[start].time, bInfo[i].time) > 0) )
        {
            swap(bInfo, ++last, i);
        }
    }

    swap(bInfo, start, last);
    quick_info(bInfo, start, last);
    quick_info(bInfo, last+1, end);
    
}

int calcu_min(char *startTime, char *endTime)
{
    int ret = 0;
    
    ret = ((endTime[3] - startTime[3]) * 10 + (endTime[4] - startTime[4])) * 
    1440 + ((endTime[6] - startTime[6]) * 10 + endTime[7] - startTime[7]) *
    60 + (endTime[9] - startTime[9]) * 10 + endTime[10] - startTime[10];

    return ret;
}

int calcu_fee(char *startTime, char *endTime, int toll[])
{
    int hstart = 0, mstart = 0, totalmin = 0, totalFee = 0;

    totalmin = calcu_min(startTime, endTime);    
    hstart = (startTime[6] - '0') * 10 + startTime[7] - '0';
    mstart = (startTime[9] - '0') * 10 + startTime[10] - '0';

    while( totalmin != 0 )
    {
        totalFee += toll[hstart];
        mstart++;

        if( 60 == mstart )
        {
            hstart = ( hstart + 1 ) % 24;
            mstart = 0;
        }
        
        totalmin--;
    }

    return totalFee;
}

int output(info *bInfo, int infoNum, int toll[])
{
    int i = 0, amount = 0, total = 0, flag = 0;
    info *cur = NULL;

    cur = bInfo;

    for( i = 1; i < infoNum; i++ )
    {
	//printf("init:%s %s %s\n", bInfo[i].name, bInfo[i].time, bInfo[i].state);
        if( strcmp(cur->name, bInfo[i].name) == 0 
        && strcmp(cur->state, "on-line") == 0
        && strcmp(bInfo[i].state, "off-line") == 0 )
        {
            amount = calcu_fee(cur->time, bInfo[i].time, toll);

            if( 0 == flag )
            {
                printf("%s %c%c\n", cur->name, cur->time[0], cur->time[1]);
            }
            
            printf("%s %s %d $%.2f\n", cur->time + 3, bInfo[i].time + 3, 
            calcu_min(cur->time, bInfo[i].time), (double)amount / 100);
            total += amount;
            flag = 1;
        }

        if( 1 == flag && strcmp(cur->name, bInfo[i].name) != 0 
            || ( 1 == flag && i == infoNum - 1 ) )
        {
            printf("Total amount: $%.2f\n", (double)total / 100);
            total = 0;
            flag = 0;
        }

	cur = bInfo+i;
    }

    return 0;    
}

int main()
{
    int toll[24] = {0};
    int i = 0, infoNum = 0;
    info *bInfo = NULL;

    for( i = 0; i < 24; i++ )
    {
        scanf("%d", toll+i);
    }
	
    scanf("%d", &infoNum);
    bInfo = (info *)malloc(sizeof(info) * infoNum);

    for( i = 0; i < infoNum; i++ )
    {
        scanf("%s %s %s", bInfo[i].name, bInfo[i].time, bInfo[i].state);
    }

    quick_info(bInfo, 0, infoNum-1);
    output(bInfo, infoNum, toll);
    
    return 0;
}


