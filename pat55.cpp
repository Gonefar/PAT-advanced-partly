#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
struct info
{
    int age;
    int totalValue;
    char name[10];
};

struct query
{
    int showNum;
    int amin;
    int amax;
};

int cmp_age(info a, info b)
{
    if( a.age > b.age)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int cmp(info a, info b)
{
    if( a.totalValue < b.totalValue )
    {
        return 0;
    }
    else if( a.totalValue == b.totalValue 
        && a.age > b.age )
    {
        return 0;
    }
    else if( a.totalValue == b.totalValue 
        && a.age == b.age 
        && strcmp(a.name, b.name) > 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int find_min_age_index(int amin, info* vinfo, int len)
{
    int i = 0;

    if( amin <= vinfo[0].age )
    {
        return 0;
    }

    if( amin > vinfo[len-1].age )
    {
        return -1;
    }
    
    for( i = 0; i < len - 1; i++ )
    {
        if( amin > vinfo[i].age && amin <= vinfo[i+1].age )
        {
            return (i+1);
        }
    }
}

int find_max_age_index(int amax, info* vinfo, int len)
{
    int i = 0;

    if( amax < vinfo[0].age )
    {
        return -1;
    }

    if( amax >= vinfo[len-1].age )
    {
        return (len-1);
    }
    
    for( i = 0; i < len - 1; i++ )
    {
        if( amax >= vinfo[i].age && amax < vinfo[i+1].age )
        {
            return i;
        }
    }
}


int main()
{
    vector <info> vinfo, vtemp;
    vector <info>::iterator it;
    info temp;
    int num, i, queryNum;
    int startIndex, endIndex, flag = 0;

    scanf("%d %d", &num, &queryNum);

    info *pinfo = new info [num];
    query *pQuery = new query [queryNum];
    for( i = 0; i < num; i++ )
    {
        scanf("%s %d %d", pinfo[i].name, &(pinfo[i].age), &(pinfo[i].totalValue));
    }
    
    for( i = 0; i < queryNum; i++ )
    {
        scanf("%d %d %d", &(pQuery[i].showNum), &(pQuery[i].amin), &(pQuery[i].amax));
    }

    sort(pinfo, pinfo+num, cmp_age);

    for( i = 0; i < queryNum; i++ )
    {              
        startIndex = find_min_age_index(pQuery[i].amin, pinfo, num);
        endIndex  = find_max_age_index(pQuery[i].amax, pinfo, num);

        if( startIndex == -1 || endIndex == -1 || endIndex < startIndex)
        {
            cout << "Case #" << i+1 << ":" << endl << "None\n";
            continue;
        }
        else
        {
            cout << "Case #" << i+1 << ":"<<endl;
            sort(pinfo+startIndex, pinfo+endIndex+1, cmp);
            
            for(int j = startIndex; j <= endIndex; j++)
            {
                flag++;
                cout << pinfo[j].name << " " << pinfo[j].age << " " << pinfo[j].totalValue<< endl;

                if( flag == pQuery[i].showNum )
                {
                    break;
                }
            }
        }

        flag = 0;
        sort(pinfo+startIndex, pinfo+endIndex+1, cmp_age);
    }
    
    return 0;
}

