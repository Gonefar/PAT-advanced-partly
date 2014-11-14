#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct stud
{
    char name[5];
};

int cmp(stud a, stud b);


int main()
{
    int studNum, courseNum, i, j;
    string curName;
    int curCouNum, curCou;
    stud tempStud;

    cin >> studNum >> courseNum;

    vector <stud> *strCourse = new vector <stud> [courseNum+1];
    for( i = 0; i < studNum; i++ )
    {
        scanf("%s %d", tempStud.name, &curCouNum);

        for( j = 0; j < curCouNum; j++ )
        {
            scanf("%d", &curCou);
            strCourse[curCou].push_back(tempStud);
        }
    }

    for( i = 1; i <= courseNum; i++ )
    {
        sort(strCourse[i].begin(), strCourse[i].end(), cmp);
    }

    for( i = 1; i <= courseNum; i++ )
    {
        printf("%d %d\n", i, strCourse[i].size());
        //cout << i << " " << strCourse[i].size() << endl;
        for( j = 0; j < strCourse[i].size(); j++ )
        {
            //cout << (strCourse[i])[j] << endl;
            printf("%s\n", &(strCourse[i])[j]);
        }
    }

    return 0;
}

int cmp(stud a, stud b)
{
    if( strcmp(a.name, b.name) > 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

