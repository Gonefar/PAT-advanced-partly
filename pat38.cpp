#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int output(vector <string> vstr)
{
    int i = 0, flag = 0;
    
    for( i = 0; i < vstr[0].length(); i++ )
    {
        if( vstr[0][i] == '0' && flag == 0 )
        {
            continue;
        }
        else
        {
            flag = 1;
        }

        cout << vstr[0][i];
    }

    for( i = 1; i < vstr.size(); i++ )
    {
        cout << vstr[i];
    }

    cout << endl;
    
    return 0;
}

int cmp(string a, string b)
{
    int i = 0;
    int azeroNum = 0, bzeroNum = 0;    

    for( i = 0; i < a.length(); i++ )
    {
        if( a[i] == '0' )
        {
            azeroNum++;
        }
        else
        {
            break;
        }
    }

    for( i = 0; i < b.length(); i++ )
    {
        if( b[i] == '0' )
        {
            bzeroNum++;
        }
        else
        {
            break;
        }
    } 

    if( azeroNum > 0 && bzeroNum > 0 && azeroNum < bzeroNum )
    {
        return 0;
    }
    

    for( i = 0; i < a.length() && i < b.length(); i++ )
    {
        if( a[i] > b[i] )
        {
            return 0;
        }
        else if( a[i] < b[i] )
        {
            return 1;
        }
    }

    if( a.length() > b.length() )
    {
        for( i = 0; i < a.length(); i++ )
        {
            if( a[i] > b[i % b.length()] )
            {
                return 0;
            }
            else if( a[i] < b[i % b.length()] )
            {
                return 1;
            }
        }
        
        return 1;
    }

    if( b.length() > a.length() )
    {
        for( i = 0; i < b.length(); i++ )
        {
            if( b[i] < a[i % a.length()] )
            {
                return 0;
            }
            else if( b[i] > a[i % a.length()] )
            {
                return 1;
            }
        }
        
        return 1;
    }

    return 1;
}

int main()
{
    int num, i, prevNum = 0;
    vector <string> vstr;
    string tmpstr;

    cin >> num;
    for( i = 0; i < num; i++ )
    {
        cin >> tmpstr;
        vstr.push_back(tmpstr);
    }

    sort(vstr.begin(), vstr.end(), cmp);

    output(vstr);

    return 0;
}

