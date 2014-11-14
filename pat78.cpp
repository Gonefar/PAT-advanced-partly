#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int isPrime(int num)
{
    int i = 0;

    if( 1 == num )
    {
        return 1;
    }
    
    if( 2 == num || 3 == num )
    {
        return 0;
    }

    for( i = 2; i * i <= num; i++ )
    {
        if( 0 == num % i )
        {
            return 1;
        }
    }

    return 0;
    
}

int checkTableSize(int *tableSize)
{
    int i = 0;

    if( 0 == isPrime(*tableSize) )
    {
        return 0;
    }

    for( i = *tableSize + 1; ; i++ )
    {
        if( 0 == isPrime(i) )
        {
            *tableSize = i;
            return 0;
        }
    }
}

int isFull(int *flag, int num)
{
    int i = 0;

    for( i = 0; i < num; i++ )
    {
        if( flag[i] == 0 )
        {
            return 1;
        }
    }


    return 0;
}

int procs(vector <int>vint, int tableSize)
{
    int num = vint.size();
    int *flag = new int [tableSize];
    int index;

    //cout << "Table size: " << tableSize << endl;
    memset(flag, 0, sizeof(int) * tableSize);   

    for( int i = 0; i < num; i++ )
    {        
        index = vint[i] % tableSize;
	 //cout << "(value:" << vint[i] << ", index:" << index << ", key:" << flag[index]<< ")";
        if( 0 != i )
        {
            cout << " ";
        }

        if( 0 == flag[index] )
        {
            cout << index;
            flag[index] = 1;
        }
        else
        {
            for( int j = 1; j <= tableSize; j++)
            {
                index = (vint[i] + j * j) % tableSize;

                if( 0 == flag[index] )
                {
                    cout << index;
                    flag[index] = 1;
                    break;
                }
                
                if( num == j )
                {
                    cout << "-";
                    break;
                }

            }
        }
    }

    cout << endl;
    delete [] flag;   
    return 0;
}

int main()
{
    int tableSize, num, i = 0, temp;
    vector<int> vint;

    cin >> tableSize >> num;


    for( i = 0; i < num; i++ )
    {
        cin >> temp;
        vint.push_back(temp);
    }

    checkTableSize(&tableSize);
    procs(vint, tableSize);

    return 0;

}

