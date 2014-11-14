#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector <char> vchar;
    vector <string> vstring;
    char tempchar;
    string tempstr, maxstr;
    int max = 0, count = 1, i, index = 0;

    while( (tempchar = cin.get()) != '\n' )
    {
        if( !((tempchar >= 'a' && tempchar <= 'z')
            || (tempchar >= 'A' && tempchar <= 'Z') 
            || (tempchar >= '0' && tempchar <= '9')) )
        {
            vchar.push_back('\0');

            if( 1 == vchar.size() )
            {
                vchar.clear();
                continue;
            }
            
            tempstr.assign(vchar.begin(), vchar.end());
            vchar.clear();
            vstring.push_back(tempstr);
            continue;
        }
        
        if( tempchar >= 'A' && tempchar <= 'Z' )
        {
            tempchar += 32;
        }

        vchar.push_back(tempchar);
    }

    if( vchar.size() > 0 )
    {
        vchar.push_back('\0');
        tempstr.assign(vchar.begin(), vchar.end());
        vstring.push_back(tempstr);
    }
    
    sort(vstring.begin(), vstring.end());
    
#if 0
    for( i = 0; i < vstring.size(); i++ )
    {
        cout << vstring[i] << " ";
    }
    cout <<endl;
#endif    

    max = 1;
    //maxstr = vstring[0];
    index = 0;

    for( i = 0; i < vstring.size() - 1; i++ )
    {
        if( vstring[i] == vstring[i+1] )
        {
            count++;
        }
        else
        {
            if( count > max )
            {
                max = count;
                //maxstr = vstring[i];
                index = i;
            }
            
            count = 1;
        }
    }
    cout << vstring[index] << " " << max << endl;

    return 0;
}

