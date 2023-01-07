#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int w; //背包耐重度
    cin >> w;
    int op;
    int temp_g;
    int temp_v;
    vector<int> g;
    vector<int> v;
    bool is_first = true;
    int n = 0;
    while (cin >> op >> temp_g >> temp_v)
    {
        if (op == -1)
            break;
        // if (op != 0 && is_first)
        // {
        g.push_back(0);
        v.push_back(0);
        //     is_first = false;
        // }
        n++;
        g.push_back(temp_g);
        v.push_back(temp_v);
    }

    int c[n + 1][w + 1];

    int items[n + 1][w + 1];
    for (int i = 0; i < n; i++)
    { // n:物品總數
        for (int j = 0; j <= w; j++)
        { // w:背包耐重度
            if (j - g[i] < 0)
            {                          // g:物品的重量
                c[i + 1][j] = c[i][j]; //無法加入新增的物品
            }
            else
            {                                                      //目前背包的可用耐重 可以裝下 目前新增的物品.
                c[i + 1][j] = max(c[i][j - g[i]] + v[i], c[i][j]); // v:物品的價值
                if (c[i][j - g[i]] + v[i] > c[i][j])
                {
                    items[i][j] = 1; //代表有加入物品.
                }
            }
        }
    }

    //印出背包裡的物品.
    for (int i = n, j = w; i >= 0; i--)
    { //從 物品總數量 和 背包耐重度 開始回溯.
        if (items[i][j] == 1)
        {                     //如果物品有被拿.
            printf("%d ", i); //印出目前物品的代號.
            j -= g[i];        //減掉目前物品的重量.
        }
    }
    cout << endl;
    printf("%d\n", c[n][w]); //印出最高價.

    return 0;
}