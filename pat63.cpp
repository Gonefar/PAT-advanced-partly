#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void setSim(vector<int> vint1, vector<int> vint2);

int main()
{
    int setNum, num, i;
    int queryNum;

    cin >> setNum;

    vector<int> *vint = new vector<int> [setNum];

    for( i = 0; i < setNum; i++ )
    {
        cin >> num;
        for( int j = 0; j < num; j++ )
        {
            int temp;
            cin >> temp;
            vint[i].push_back(temp);
        }

        sort(vint[i].begin(), vint[i].end());
    }

    cin >> queryNum;
    int *index1 = new int [queryNum];
    int *index2 = new int [queryNum];
    
    for( i = 0; i < queryNum; i++ )
    {
        cin >> index1[i] >> index2[i];
    }

    for( i = 0; i < queryNum; i++ )
    {
        setSim(vint[(index1[i]-1)], vint[(index2[i]-1)]);
    }
    
    return 0;
    
}

void setSim(vector<int> vint1, vector<int> vint2)
{
    int index1 = 0, index2 = 0;
    int disCom = 0, disTot = 0, flag = 0;
    int size1 = vint1.size(), size2 = vint2.size();
/*
    for( int i = 0; i < vint1.size(); i++ )
    {
        cout << vint1[i] << " ";
    }
    cout << endl;

    for( int i = 0; i < vint2.size(); i++ )
    {
        cout << vint2[i] << " ";
    }
    cout << endl;*/

    while( index1 < size1 - 1 )
    {
        if( vint1[index1] == vint1[index1+1] )
        {
            disCom++;
        }
        index1++;
    }

    while( index2 < size2 - 1 )
    {
        if( vint2[index2] == vint2[index2+1] )
        {
            disCom++;
        }
        index2++;
    }

    disTot = size1 + size2 - disCom;
    disCom = 0;

    index1 = index2 = 0;
    while( 1 )
    {
        while( index1 < size1 - 1 )
        {
            if( vint1[index1] == vint1[index1+1] )
            {
                index1++;
            }
            else
            {
                break;
            }
        }

        while( index2 < size2 - 1 )
        {
            if( vint2[index2] == vint2[index2+1] )
            {
                index2++;
            }
            else
            {
                break;
            }
        }

        if( index1 < size1 && index2 < size2 )
        {            
            if( vint1[index1] == vint2[index2] )
            {
                disCom++;
                index1++;
                index2++;
            }
            else
            {               
                if( vint1[index1] < vint2[index2] )
                {
                    index1++;
                }
                else
                {
                    index2++;
                }
            }
        }
        else if( index1 >= size1 && index2 >= size2 )
        {          
            break;
        }
        else
        {           
            if( index2 >= size2 )
            {
                index1++;
            }

            if( index1 >= size1 )
            {
                index2++;
            }   
        
        }
        
    }

    //cout << disCom << " " << disTot << endl;
    printf("%.1f%\n", (double)disCom / (disTot - disCom)* 100);
    return;
}

