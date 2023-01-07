#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> d;
vector<int> t;
vector<int> ans;
int bs(int le, int ri, int val)
{
    if (le == ri)
    {
        return le;
    }
    int mid = (le + ri - 1) / 2;
    if (val <= t[mid])
    {
        return bs(le, mid, val);
    }
    else
    {
        return bs(mid + 1, ri, val);
    }
}
signed main()
{
    int n;
    cin >> n;
    d.clear();
    d.resize(n + 1);
    t.clear();
    t.resize(n + 1);
    t[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        t[i] += t[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (t[n] < d[i] + t[i - 1])
        {
            cout << "-1 ";
        }
        else
        {
            cout << bs(0, n, t[i - 1] + d[i]) << " ";
        }
    }
    cout << endl;

    return 0;
}