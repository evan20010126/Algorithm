#include <bits/stdc++.h>
using namespace std;
int total;
vector<pair<int, pair<int, int>>> vec;
vector<vector<int>> ans;
vector<int> reans;
vector<int> ansnu;

struct compa
{
    bool operator()(int a, int b)
    {
        return ((double)vec[a].second.second / (double)vec[a].second.first) > ((double)vec[b].second.second / (double)vec[b].second.first);
    }
};

void copy(int n, int m)
{
    for (int i = 0; i < ansnu[m]; i++)
    {
        ans[n][i] = ans[m][i];
    }
    ansnu[n] = ansnu[m];
}

int main()
{
    cin >> total;
    int a1, a2, a3;
    reans.resize(total + 1, 0);
    ans.resize(total + 1, vector<int>(total + 1));
    ansnu.resize(total + 1, 0);
    while (cin >> a1 >> a2 >> a3)
    {
        if (a1 == -1 && a2 == -1)
            break;
        vec.push_back(make_pair(a1, make_pair(a2, a3)));
    }

    int k;
    for (int j = 0; j < vec.size(); j++)
    {
        for (int i = total; i >= vec[j].second.first; i--)
        {
            k = reans[i - vec[j].second.first] + vec[j].second.second;
            if (k > reans[i])
            {
                reans[i] = k;
                copy(i, i - vec[j].second.first);
                ans[i][ansnu[i]] = j;
                ansnu[i]++;
            }
        }
    }

    sort(ans[total].begin(), ans[total].begin() + ansnu[total], compa());

    for (int i = 0; i < ansnu[total]; i++)
    {
        cout << vec[ans[total][i]].first << " ";
    }
    cout << endl
         << reans[total] << endl;

    return 0;
}