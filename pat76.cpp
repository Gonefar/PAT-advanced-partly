#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#if 0

#define min(a, b) ((a)>(b)?(b):(a))
int process(vector <int> *pvint, int num, int user, int level)
{
    int depth[1000];
    int flag[1000] = {0};

    for( int i = 0; i < 1000; i++ )
    {
        depth[i] = -1;
    }

    depth[user-1] = 0;
    flag[user-1] = 1;
    for( int i = 0; i < level; i++ )
    {
        for( int j = 0; j < num; j++ )
        {
            if(flag[j] == 0)
            {
                for( vector <int>::iterator iter = pvint[j].begin(); iter != 
                pvint[j].end(); iter++)
                {
                    if(depth[*iter-1] >= 0 )
                    {
                        if(depth[j] > 0)
                        {
                            depth[j] = min(depth[j], depth[*iter-1]+1);
                        }
                        else
                        {
                            depth[j] = depth[*iter-1]+1;
                        }
                        flag[j] = 1;
                    }
                }
            }
        }
    }

    int sum = 0;
    for( int i = 0; i < num; i++ )
    {
        //printf("%d:%d\n", i+1, depth[i]);
        if(depth[i] > 0 && depth[i] <= level)
        {
            sum++;
        }
    }

    cout << sum << endl;
}

int main()
{
    int num, level, tmp, user, qnum;
    //char connMat[1001][1001];
    double price, percent, sum = 0;

    cin >> num >> level;

    vector <int> *pvint = new vector <int> [num];

    for( int i = 0; i < num; i++ )
    {
        scanf("%d", &tmp);
        for( int j = 0; j < tmp; j++ )
        {
            scanf("%d", &user);
            pvint[i].push_back(user);
        }
    }

    scanf("%d", &qnum);
    for( int i = 0; i < qnum; i++ )
    {
        scanf("%d", &user);
        process(pvint, num, user, level);
    }

    return 0;
}
#else
typedef struct _point
{
    int num;
    int level;
}point;

int process(int num, int user, int level, char connMat[][1000])
{
    queue <point> q;
    int count = 0;
    int flag[1000] = {0};
    point node, top;

    for(; !q.empty(); q.pop());

    node.num = user;
    node.level = 0;
    flag[user-1] = 1;
    q.push(node);
    while(!q.empty())
    {
        top = q.front();
        q.pop();
        for(int i = 1; i <= num; i++ )
        {
            if(flag[i-1] == 0 && connMat[i-1][top.num-1] == 1)
            {
                flag[i-1] = 1;
                node.num = i;
                node.level = top.level + 1;
                if( node.level > 0 && node.level <= level)
                {
                    q.push(node);
                    count++;
                }
                
            }
        }
    }

    return count;

    
}

int main()
{
    int num, level, tmp, user, qnum;
    char connMat[1000][1000] = {0};
    double price, percent, sum = 0;
    int depth[1000];

    for( int i = 0 ; i < 1000; i++ )
    {
        depth[i] = -1;
    }

    cin >> num >> level;
    for( int i = 0; i < num; i++ )
    {
        scanf("%d", &tmp);
        for( int j = 0; j < tmp; j++ )
        {
            scanf("%d", &user);
            connMat[i][user-1] = 1;
        }
    }

    scanf("%d", &qnum);
    for( int i = 0; i < qnum; i++ )
    {
        scanf("%d", &user);
        printf("%d\n", process(num, user, level, connMat));
    }

    return 0;    
}

#endif
