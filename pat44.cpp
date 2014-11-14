#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int record(vector <int> &vres, int start ,int end, int sum, int amt)
{
    if( sum >= amt )
    {
        if( vres.size() == 0 )
        {
            vres.push_back(start);
            vres.push_back(end);
            vres.push_back(sum);
        }
        else
        {
            if( sum > vres[2] )
            {
                return 1;
            }

            if( sum < vres[2] )
            {
                vres.clear();
            }
            
            vres.push_back(start);
            vres.push_back(end);
            vres.push_back(sum);                    
        }
    }

    return 0;
}

int main()
{
    int dnum, amt, i = 0, j = 0;
    int sum = 0, jmp = 0;
    vector <int> vres;

    scanf("%d%d", &dnum, &amt);

    int *darr = new int [dnum];
    for( i = 0; i < dnum; i++ )
    {
        scanf("%d", darr+i);
    }

    for( i = 0; i < dnum; i++ )
    {
        sum = 0;
        jmp = 0;
        for( j = i; j < dnum; j++ )
        {
            sum += darr[j];
            
            if( sum >= amt )
            {
                if( vres.size() == 0 )
                {
                    vres.push_back(i);
                    vres.push_back(j);
                    vres.push_back(sum);
                }
                else
                {
                    if( sum > vres[2] )
                    {
                        continue;
                    }
            
                    if( sum < vres[2] )
                    {
                        vres.clear();
                    }
                    
                    vres.push_back(i);
                    vres.push_back(j);
                    vres.push_back(sum);                    
                }
            }
            
        }   
    }

    for( i = 0; i < vres.size() / 3; i++ )
    {
        printf("%d-%d\n", vres[3 * i ]+1 ,vres[3 * i + 1]+1);
    }
    
    return 0;
}


