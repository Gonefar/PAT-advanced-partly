#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long int getNextFactor(long int curFactor);
inline int isPrime(long int num);

int main()
{
    long int num, curfactor, curtimes = 0, i, init;
    vector <long int> factor, times;
    int flag = 0;

    cin >> num;
    init = num;
    curfactor = 2;
    int rec = 0;
    if( 1 == num )
    {
        cout << "1=1\n";
        return 0;
    }

    while(1)
    {
        if( 0 == isPrime(num) || 1 == num )
        {
            break;
        }

        while( 0 == num % curfactor )
        {
            curtimes++;
            num /= curfactor;
            flag = 1;
          //  cout <<  "1 " << num << " " << curtimes << " " << curfactor<< endl;
        }
        //cout << "2 " << num << " " << curtimes <<" "  << curfactor << endl;
        if( 1 == flag )
        {
            factor.push_back(curfactor);
            times.push_back(curtimes);
            curtimes = 0;
            flag = 0;
        }

        curfactor = getNextFactor(curfactor);
    }

    if( num > 1 )
    {
        factor.push_back(num);
        times.push_back(1);
    }
    
    if( 0 == factor.size() )
    {
        cout << num << "=" << num;
    }
    else
    {
        cout << init << "=";
        for( i = 0; i < factor.size(); i++ )
        {
            if( i > 0 )
            {
                if( 1 == times[i] )
                {
                    cout << "*" << factor[i];
                }
                else
                {
                    cout << "*" << factor[i] << "^" << times[i];
                }
            }
            else
            {
                if( 1 == times[i] )
                {
                    cout << factor[i];
                }
                else
                {
                    cout << factor[i] << "^" << times[i];
                }
            }
        }
    }

    cout << endl;
    
    return 0;
}

long int getNextFactor(long int curFactor)
{
    long int i = 0;

    for( i = curFactor+1; ; i++ )
    {
        if( 0 == isPrime(i) )
        {
            return i;
        }
    }
}

inline int isPrime(long int num)
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

    for( i = 2; i *i <= num; i++ )
    {
        if( 0 == num % i )
        {
            return 1;
        }
    }

    return 0;
}
