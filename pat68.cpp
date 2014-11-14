#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct element
{
    int val;
    int index;
};

int mySum(vector <element> proj)
{
    int sum = 0;

    if( 0 == proj.size() )
    {
        return 0;
    }
    else
    {
        for( int j = 0; j < proj.size(); j++ )
        {
            sum += proj[j].val;
        }
    }

    return sum;
}

int show(vector <element> proj)
{
    int i = 0;

    for( i = 0; i < proj.size(); i++ )
    {
        if( i > 0 )
        {
            cout << " ";
        }

        cout << proj[i].val;
    }
    cout << endl;

    return 0;
}

int isEndLess(vector <element> proj)
{
    int i = 0;

    if( proj.size() == 1 )
    {
        return 0;
    }
    
    for( i = 0; i < proj.size() - 1; i++ )
    {
        if( proj[i].index != proj[i+1].index + 1 )
        {
            return 1;
        }
    }

    return 0;
}

int process(int acoin[], int num, int payAmt)
{
    vector <element> proj;
    int sum = 0, i = 0, lastIndex = 0;
    element tmp = {acoin[0], 0};

    proj.push_back(tmp);

    while(1)
    {
        sum = mySum(proj);
        //show(proj);
        
        if( sum < payAmt )
        {
            if( lastIndex == num - 1 )
            {
                if( 0 == isEndLess(proj) )
                {
                    cout << "No solution\n";
                    return 1;
                }
                else
                {
                    //lastIndex = proj[0].index;
                    //proj.clear();
                    proj.pop_back();
                    lastIndex = proj[proj.size() - 1].index;
                    proj.pop_back();                     
                }
            }
            else
            {
                lastIndex++;
                tmp.val = acoin[lastIndex];
                tmp.index = lastIndex;
                proj.push_back(tmp);
            }
        }
        else if( sum > payAmt )
        {
            if( lastIndex == num - 1 &&  0 == isEndLess(proj) )
            {
                cout << "No solution\n";
                return 1;
            }

            if( proj.size() <= 1 )
            {
                cout << "No solution\n";
                return 1;
            }

            proj.pop_back();
            lastIndex = proj[proj.size() - 1].index;
            proj.pop_back(); 
        }
        else
        {
            show(proj);
            return 0;
        }
    }

    return 0;
}

int main()
{
    int coinNum, payAmt, i;

    cin >> coinNum >> payAmt;
    int *acoin = new int [coinNum];

    for( i = 0; i < coinNum; i++ )
    {
        cin >> acoin[i];
    }

    sort(acoin, acoin+coinNum);
    process(acoin, coinNum, payAmt);
    
    return 0;
}

