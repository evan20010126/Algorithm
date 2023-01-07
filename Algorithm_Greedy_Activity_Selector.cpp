#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

//global variable
int length = 0;
int arr_answer[5000];
//

struct my_struct
{
    int start;
    int finish;
};

void GREEDY_ACTIVITY_SELECTOR(my_struct table[])
{
    //length global variable
    vector<int> temp_answer;
    int i = 1;
    temp_answer.push_back(i);
    for (int m = 2; m < length; m++)
    {
        if (table[m].start >= table[i].finish)
        {
            temp_answer.push_back(m);
            i = m;
        }
    }

    for (int k = 0; k < temp_answer.size(); k++)
    {
        arr_answer[k] = temp_answer[k];
    }
}

int main()
{

    my_struct table[30000];

    for (int i = 0; i < 5000; i++)
    {
        arr_answer[i] = INT_MIN;
    }
    // for (int i = 0; i < 30000; i++)
    // {
    //     table[i].start = INT_MIN;
    //     table[i].finish = INT_MIN;
    // }
    int start, finish;
    int nul;
    while (cin >> nul >> start >> finish)
    {
        length++;
        table[length].start = start;
        table[length].finish = finish;
    }
    GREEDY_ACTIVITY_SELECTOR(table);

    int p = 0;

    while (arr_answer[p] != INT_MIN)
    {
        cout << arr_answer[p] << " ";
        p++;
    }
    
    cout << endl;

    return 0;
}