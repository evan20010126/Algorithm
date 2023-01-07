#include <iostream>
#include <algorithm>
using namespace std;
// n: n個巴士driver, n條早晨路線,n條傍晚路線 長度各不同
// d: 總路徑超過d d小時候每小時r元加班費
// r: 最小加班費

//要避免小的加小的((因為小的加小的會有空出來但不用加班費的時間
//盡量把大的組合多出來的時間補給小的組合 >>> 小配大
int main()
{
    int n, d, r;
    while (cin >> n >> d >> r)
    {
        int sum = 0;
        if (!n && !d && !r)
            break;
        int morning[n];
        int evening[n];
        for (int k = 0; k < n; k++)
            cin >> morning[k];
        for (int k = 0; k < n; k++)
            cin >> evening[k];
        sort(morning, morning + n);
        sort(evening, evening + n);
        for (int i = 0; i < n; i++)
        {
            int temp = morning[i] + evening[n - i - 1] - d;
            if (temp > 0)
                sum += temp * r;
        }
        cout << sum << endl;
    }
    return 0;
}
