#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
    int id;
    int totalScore;
    int score[5];
    int rightNum;
    int rank;
};

int cmp(info a, info b)
{
    if( a.totalScore < b.totalScore)
    {
        return 0;
    }
    else if( a.totalScore == b.totalScore )
    {
        if( a.rightNum < b.rightNum )
        {
            return 0;
        }
        else if( a.rightNum == b.rightNum )
        {
            if( a.id > b.id )
            {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    vector <info> vinfo;
    int peoNum, proNum, subNum;
    int id, proIndex, sco;
    int i, j;

    cin >> peoNum >> proNum >> subNum;

    info * pinfo = new info [peoNum];

    int * score = new int [proNum];

    for( i = 0; i < peoNum; i++ )
    {
        pinfo[i].id = i + 1;
        pinfo[i].totalScore = -1;
        pinfo[i].rightNum = 0;

        for( j = 0; j < proNum; j++ )
        {
            pinfo[i].score[j] = -2;
        }
    }
    
    for( i = 0; i < proNum; i++ )
    {
        cin >> score[i];
    }

    for( i = 0; i < subNum; i++ )
    {
        cin >> id >> proIndex >> sco;

        if( sco == score[proIndex - 1] )
        {
            pinfo[id-1].rightNum ++;
        }
        
        if( pinfo[id -1].score[proIndex - 1] < sco )
        {
            pinfo[id -1].score[proIndex - 1] = sco;
        }
    }

    for( i = 0 ; i < peoNum; i++ )
    {
        for( j = 0; j < proNum; j++ )
        {
            if( pinfo[i].score[j] < 0 )
            {
                continue;
            }

            if( pinfo[i].totalScore < 0 )
            {
                pinfo[i].totalScore = pinfo[i].score[j];
            }
            else
            {
                pinfo[i].totalScore += pinfo[i].score[j];
            }
        }
    }

    sort(pinfo, pinfo+peoNum, cmp);

    int rank = 1;
    pinfo[0].rank = 1;
    for( i = 0; i < peoNum - 1; i++ )
    {
        rank++;
        if( pinfo[i+1].totalScore == pinfo[i].totalScore )
        {
            pinfo[i+1].rank = pinfo[i].rank;
        }
        else
        {
            pinfo[i+1].rank = rank;
        }
    }

    for( i = 0; i < peoNum; i++ )
    {
        if( pinfo[i].totalScore >= 0 )
        {
            printf("%d %05d %d ", pinfo[i].rank, pinfo[i].id, pinfo[i].totalScore);
            for( j = 0; j < proNum; j++ )
            {
                if( j != 0 )
                {
                    printf(" ");
                }
                
                if( pinfo[i].score[j] == -2 )
                {
                    printf("-");
                }
                else if( pinfo[i].score[j] == -1 )
                {
                    printf("0");
                }
                else
                {
                    printf("%d", pinfo[i].score[j]);
                }
            }
            printf("\n");
        }

    }

    return 0;
}

