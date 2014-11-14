#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct stud
{
    string name;
    int totalCourse;
    vector <int> course;
};

#define MAX (26*26*26*10)
int get_key(char *str);

int main()
{
    int courseNum, studNum;
    int curCourse, curStudNum, index, i, j;
    char tempName[5];

    vector <int> *studRecord = new vector <int> [MAX];
    cin >> studNum >> courseNum;
    char studName[studNum][5];

    for( i = 0; i < courseNum; i++ )
    {
        cin >> curCourse >> curStudNum;
        for( j = 0; j < curStudNum; j++ )
        {
            scanf("%s", tempName);
            index = get_key(tempName);
            studRecord[index].push_back(curCourse);
        }
    }

    for( i = 0; i < studNum; i++ )
    {
        scanf("%s", studName[i]);
        index = get_key(studName[i]);
        sort(studRecord[index].begin(), studRecord[index].end());
    }

    for( i = 0; i < studNum; i++ )
    {
        index = get_key(studName[i]);
        printf("%s %d", studName[i], studRecord[index].size());

        for( j = 0; j < studRecord[index].size(); j++ )
        {
            printf(" %d", (studRecord[index])[j]);
        }
        cout << endl;
    }
    
    return 0;
}

int get_key(char *str)
{
    int len = strlen(str);
    int i = 0, ret = 0;

    for( i = 0; i < len - 1; i++ )
    {
        ret = ret * 26 + str[i] - 'A';
    }

    ret = ret * 10 + str[len-1] - '0';

    return ret;
}

