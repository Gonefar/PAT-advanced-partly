#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_neg_end(vector <int> vn, int &end)
{
    int i = 0;

    end = -1;
    if( vn[0] >= 0 )
    {
        return -1;
    }

    if( vn.size() == 1 )
    {
        end = 0;
        return 0;
    }
    
    for( i = 0; i < vn.size()-1; i++ )
    {
        if( vn[i] < 0 && vn[i+1] >= 0 )
        {
            end = i;
            return 0;
        }
    }

    end = vn.size() - 1;
    return 0;
}

int find_pos_start(vector <int> vn, int &start)
{
    int i = 0;

    start = -1;
    if( vn[vn.size()-1] <= 0 )
    {
        return -1;
    }

    if( vn.size() == 1 )
    {
        start = 0;
        return 0;
    }
    
    for( i = 0; i < vn.size()-1; i++ )
    {
        if( vn[i] <= 0 && vn[i+1] > 0 )
        {
            start = i+1;
            return 0;
        }
    }

    start = 0;
    return 0;
}

int main()
{
    vector <int> nc, np;
    int nct, npt, num, i, max = 0;

    cin >> num;

    for( i = 0; i < num; i++ )
    {
        cin >> nct;
        nc.push_back(nct);
    }

    cin >> num;
    for( i = 0; i < num; i++ )
    {
        cin >> npt;
        np.push_back(npt);
    }

    sort(nc.begin(), nc.end());
    sort(np.begin(), np.end());

    int nc_neg_end, nc_pos_start, np_neg_end, np_pos_start;
    find_neg_end(nc, nc_neg_end);
    find_pos_start(nc, nc_pos_start);
    find_neg_end(np, np_neg_end);
    find_pos_start(np, np_pos_start); 

    int nc_index = 0, np_index = 0;
    for(nc_index = 0, np_index = 0; nc_index <= nc_neg_end && np_index <= 
    np_neg_end; nc_index++, np_index++)
    {
        max += nc[nc_index] * np[np_index];
    }

    for(nc_index = nc.size() - 1, np_index = np.size() - 1; nc_pos_start >= 0 &&
        np_pos_start >= 0 && nc_index >= nc_pos_start && np_index >= np_pos_start; nc_index--, np_index--)
    {
        max += nc[nc_index] * np[np_index];
    }

    cout << max << endl;
}

