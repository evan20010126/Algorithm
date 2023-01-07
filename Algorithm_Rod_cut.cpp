#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;
vector<int> p;

int bottom_up_cut_rod(int n)
{
    int r[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++)
        {
            q = max(q, p[i] + r[j - i]);
        }
        r[j] = q;
    }
    return r[n];
}
int main()
{
    p.clear();
    int l;
    cin >> l;
    int input1, input2;

    p.push_back(0);
    while (cin >> input1 >> input2)
    {
        if (input1 == 0 && input2 == 0)
            break;
        p.push_back(input2);
    }
    cout << bottom_up_cut_rod(l) << endl;

    return 0;
}