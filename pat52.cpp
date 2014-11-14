#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAX 100000

struct node
{
    int add;
    int key;
    int next;
};

int swap(node *pList, int i, int j)
{
    node temp;
    memcpy(&temp, pList + i, sizeof(node));
    memcpy(pList + i, pList + j, sizeof(node));
    memcpy(pList + j, &temp, sizeof(node));
}

int quick_sort_node(node *pList, int start, int end)
{
    int last = 0, i = 0, cur = 0;
    
    if( end - start <= 0 )
    {
        return 0;
    }

    swap(pList, start, start + rand() % (end - start) );
    last = start;
    
    for( i = start + 1; i <= end; i++ )
    {
        if( pList[i].key < pList[start].key )
        {
            swap(pList, ++last, i);
        }
    }

    swap(pList, last, start);
    quick_sort_node(pList, start, last);
    quick_sort_node(pList, last+1, end);
}

int procs(node*pList, int num, int startAdd)
{
    int i = 0, curAdd = startAdd;

    quick_sort_node(pList, 0, num-1);
    for( i = 0; i < num; i++ )
    {
        cout << setfill('0') << setw(5) << pList[i].add << " "
               << pList[i].key << " ";
        if( -1 == pList[i].next)
        {
            cout << "-1\n";
        }
        else
        {
            cout << setfill('0') << setw(5) << pList[i].next << endl;
        }
    }

    return 0;
}

int main()
{
    node* pList = new node [MAX];
    int i = 0, num = 0, startAdd = 0;
    node temp;

    memset(pList, 0, sizeof(node) * MAX);
    cin >> num >> startAdd;

    for( i = 0; i < num; i++ )
    {
        cin >> temp.add >> temp.key >> temp.next;
        pList[i].add = temp.add;
        pList[i].key = temp.key;
        pList[i].next = temp.next;
    }

    procs(pList, num, startAdd);

    return 0;
}

