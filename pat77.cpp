#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int procs(char str[][257], int num)
{
    int i = 0, j = 0, index = 0;
    int len[num], exitFlag = 0;
    char ch;

    for( i = 0; i < num; i++ )
    {
        len[i] = strlen(str[i]);
        //printf("%s\n", str[i]);
        //cout << (string *)str[i] << endl;
    }
    
    while(1)
    {
        if( len[0] - 1 - index < 0 )
        {
            exitFlag = 1;
            break;
        }
        else
        {
            ch = str[0][len[0] - 1 - index];
        }
        
        for( i = 1; i < num; i++ )
        {
            if( 0 == len[i] )
            {
                index = -1;
                exitFlag = 1;
                break;
            }

            if(  len[i] - 1 - index < 0 || ch != str[i][len[i] - 1 - index] )
            {
                exitFlag =1;
                break;
            }
        }

        if( 1 == exitFlag )
        {
            break;
        }

        index++;
    }

    if( index <= 0 )
    {
        cout << "nai" << endl;
    }
    else
    {
        printf("%s\n", str[0] + len[0] - index);
        //cout << *((string *)(str[0] + len[0] - index)) << endl;
    }

    return 0;
}

int main()
{
    int num;
    const int Max = 257;

    cin >> num;
    cin.get();
    char str[num][Max];
    memset(str, 0, sizeof(char) * num * Max);

    int j = 0;

    for( int i = 0; i < num; i++ )
    {
        while( '\n' != (str[i][j] = cin.get() ) )
        {
            j++;
        }

        str[i][j] = '\0';
        j = 0;
    }
    
    procs(str, num);

    //cin.get();
    return 0;
	
}

