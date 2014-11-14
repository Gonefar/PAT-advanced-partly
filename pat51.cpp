#include <cstdio>
#include <stack>

using namespace std;

int process(int *checkArray, int seqLen, int stackSize)
{
    int ret = 0;
    int inflag = checkArray[0], outflag = checkArray[0];
    int *outstack = new int [stackSize];

    if( outflag > stackSize )
    {
        //printf("<overflow1>\n");
        ret = -1;
    }
    else
    {
        for( int i = 0; i < outflag; i++ )
        {
            outstack[i] = i + 1;
        }
    }

    if( ret == 0 )
    {
        for( int i = 0; i < seqLen; i++ )
        {
            //printf(">>>><i:%d, ckArr:%d, out:%d, outflag:%d, inflag:%d>\n", i, 
            //checkArray[i], outstack[outflag-1], outflag, inflag);

            if( outflag == 0 || checkArray[i] > outstack[outflag-1] )
            {
                if( inflag == checkArray[i] )
                {
                    break;
                }                
                if( checkArray[i] - inflag + outflag > stackSize )
                {
                    ret = -1;
                    //printf("<overflow2>\n");
                    break;
                }
                else
                {
                    for(int j = 0; j < checkArray[i] - inflag; j++)
                    {
                        outstack[outflag+j] = inflag + j + 1;
                        printf("<<out:%d, flag:%d\n", outstack[outflag+j], outflag);
                    }
                   
                    outflag = checkArray[i] - inflag;
                    inflag = checkArray[i];
                    i--;
                }


            }
            else if( checkArray[i] == outstack[outflag-1] )
            {
                //printf("<i:%d, ckArr:%d, out:%d, outflag:%d>\n", i, 
                //checkArray[i], outstack[outflag-1], outflag);
                outflag--;
            }
            else
            {
                //printf("<i:%d, ckArr:%d, out:%d, outflag:%d>\n", i, 
               // checkArray[i], outstack[outflag-1], outflag);                
                //printf("<Not equal>\n");
                ret = -1;
                break;
            }
        }
    }

    if( -1 == ret )
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }

    return 0;
}

int main()
{
    int stackSize, seqLen, checkNum;

    scanf("%d%d%d", &stackSize, &seqLen, &checkNum);
    int *checkArray = new int [seqLen];
    
    for(int i = 0; i < checkNum; i++)
    {
        for(int j = 0; j < seqLen; j++)
        {
            scanf("%d", checkArray+j);
        }
        
        process(checkArray, seqLen, stackSize);
    }

    return 0;
}

