#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define EMPTY 0

typedef struct _info
{
    char time[10];
    int serveTime;
    int winID;
    int startServe;
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
        if( strcmp(bInfo[start].time, bInfo[i].time) > 0)
        {
            swap(bInfo, ++last, i);
        }
    }

    swap(bInfo, start, last);
    quick_info(bInfo, start, last);
    quick_info(bInfo, last+1, end);
    
}

int get_wait_num(info *Linfo, int pepNum)
{
    int i = 0, num = 0;

    for( i = 0; i < pepNum; i++ )
    {
        if( strcmp(Linfo[i].time, "17:00:00") < 0 )
        {
            num++;
        }
    }

    return num;
}

int calcu_wait_time_sec(char *arriveTime, char *startServe)
{
    int ret = 0;

    ret = ((startServe[0] - arriveTime[0]) * 10 + startServe[1] - arriveTime[1]) * 3600
            +((startServe[3] - arriveTime[3]) * 10 + startServe[4] - arriveTime[4]) * 60
            +((startServe[6] - arriveTime[6]) * 10 + startServe[7] - arriveTime[7]);

    return ret;
}

int get_empty_win(int *winState, int winNum)
{
    int i = 0;

    for( i = 0; i < winNum; i++ )
    {
        if( winState[i] == EMPTY )
        {
            return i;
        }
    }

    return -1;
}

int is_win_full(int *winState, int winNum)
{
    int i = 0;

    for( i = 0; i < winNum; i++ )
    {
        if( winState[i] == EMPTY )
        {
            return 1;
        }
    }

    return 0;
}

int show_win(int *winState, int winNum)
{
    int i = 0;

    for( i = 0; i < winNum; i++ )
    {
        printf("Window state:%d %d\n", i, winState[i]);
    }

    return 0;
}

int serve(info *Linfo, int pepNum, int winNum)
{
    int *winState = (int *)malloc(sizeof(int) * winNum);
    int waitNum = get_wait_num(Linfo, pepNum);
    int waitTime = 0, empty_winID = -1, index = 0, curTime = 0;
    int i = 0, infoID = 0, initFlag = 0;

    memset(winState, 0, sizeof(int) * winNum);
    for( i = 0; i < winNum; i++ )
    {
        if( strcmp(Linfo[i].time, "08:00:00") < 0 )
        {               
            Linfo[index].winID= i;
            waitTime += calcu_wait_time_sec(Linfo[i].time, "08:00:00");
            //printf("wait time 0:%d cur time:%d\n", waitTime, curTime);
            winState[i] = index+1;
            index++;
        }
        else
        {
            initFlag = 1;
            break;
        }
    }
    
    while(1)
    {
        if( is_win_full(winState, winNum) == 0 )
        {
            initFlag = 0;
        }
        
        if( is_win_full(winState, winNum) != 0 && 
            (calcu_wait_time_sec(Linfo[index].time, "08:00:00") >= 0 
              || calcu_wait_time_sec("08:00:00", Linfo[index].time) <= curTime ))
        {
            //show_win(winState, winNum);
           
            for( i = 0; i < winNum; i++ )
            {
                if( (empty_winID = get_empty_win(winState, winNum)) >= 0 )
                {
                    Linfo[index].winID = empty_winID;
                    

                    if( calcu_wait_time_sec(Linfo[index].time, "08:00:00") >= 0 )
                    {
                        waitTime += calcu_wait_time_sec(Linfo[index].time, "08:00:00") + curTime;
                    }
                    else
                    {

                        if( initFlag == 0 )
                        {
                            waitTime += curTime - calcu_wait_time_sec("08:00:00", Linfo[index].time);
                        }
                    }
                    //printf("wait time:%d cur time:%d cur user:%s\n", waitTime, curTime, Linfo[index].time);
                    winState[empty_winID] = index+1;
                    index++;
                    if( index == pepNum )
                    {
                        break;
                    } 
                    break;
                }
            }
        }

        if( index == pepNum )
        {
            break;
        } 
        
        curTime++;
        for( i = 0; i < winNum; i++ )
        {
            infoID = winState[i] - 1;
            if( infoID >= 0 )
            {
                Linfo[infoID].startServe++;
                if( Linfo[infoID].startServe >= Linfo[infoID].serveTime * 60  || Linfo[infoID].startServe >= 3600 )
                {
                    winState[i] = EMPTY;
                    //Linfo[infoID].startServe = 0;
                    //printf("Finish0:%s cur time:%d\n", Linfo[infoID].time, curTime);
                }
            }
        }
    }

    if( 0 == waitNum)
    {
        printf("0.0\n");
    }
    else
    {
        printf("%.1f\n", (double)waitTime / waitNum / 60);
    }
}

int prePro(info *Linfo, int *pepNum)
{
    int i = 0;

    for( i = 0; i < *pepNum; i++ )
    {
        //printf("prePro:%s %d\n", Linfo[i].time, Linfo[i].serveTime);
        if( strcmp(Linfo[i].time, "17:00:01") >= 0 )
        {
            *pepNum = i;
        }
    }

    return 0;
}

int main()
{
    int pepNum = 0, winNum = 0, i = 0, tempServe = 0;
    info *Linfo = NULL;
    char tempTime[10];
    
    scanf("%d%d", &pepNum, &winNum);
    Linfo = (info *)malloc(sizeof(info) * pepNum);
    memset(Linfo, 0, sizeof(info) * winNum);

    for( i = 0; i < pepNum; i++ )
    {
        scanf("%s %d", Linfo[i].time, &(Linfo[i].serveTime));
    }

    quick_info(Linfo, 0, pepNum-1);
    prePro(Linfo, &pepNum);
    serve(Linfo, pepNum, winNum);
    
    return 0;
}

