#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &s)
{
    if (s.size() == 0)
        return 0;
    else
    {
        vector<int> v;
        v.push_back(s[0]);

        for (int i = 1; i < s.size(); ++i)
        {
            int n = s[i];

            if (n > v.back())
                v.push_back(n);
            else
                *lower_bound(v.begin(), v.end(), n) = n;
        }
        return v.size();
    }
}

int main()
{
    vector<int> s;
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        s.push_back(k);
    }
    printf("%d\n", LIS(s));

    return 0;
}