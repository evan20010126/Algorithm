#include <bits/stdc++.h>
using namespace std;

int total;
vector<pair<int, pair<int, int>>> vec;
struct cmd
{
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return ((double)a.second.second / (double)a.second.first) > ((double)b.second.second / (double)b.second.first);
    }
};
int revenue;
int re[100000];
int ansma;
int answer;
int ans[10000];
void copy()
{
    for (int i = 0; i < revenue; i++)
    {
        ans[i] = re[i];
    }
    answer = revenue;
}
void dfs(int have, int now, int val)
{
    if (vec.size() == now)
    {
        if (val > ansma)
        {
            copy();
            ansma = val;
        }
        return;
    }
    else
    {
        if (vec[now].second.first <= have)
        {
            re[revenue] = vec[now].first;
            revenue++;
            dfs(have - vec[now].second.first, now + 1, val + vec[now].second.second);
            revenue--;
        }
        dfs(have, now + 1, val);
    }
}

int main()
{
    cin >> total;
    int a1, a2, a3;
    while (cin >> a1 >> a2 >> a3)
    {
        if (a1 == -1 && a2 == -1)
            break;
        vec.push_back(make_pair(a1, make_pair(a2, a3)));
    }
    sort(vec.begin(), vec.end(), cmd());

    dfs(total, 0, 0);
    for (int i = 0; i < answer; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl
         << ansma << endl;
    return 0;
}