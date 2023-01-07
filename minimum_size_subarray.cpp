#include <bits/stdc++.h>
#define MAX_SIZE 9999999
using namespace std;
int nums[MAX_SIZE];
int minSubArrayLen(int s, int numsSize)
{
    int head = 0, tail = 0;
    int minRet = numsSize;
    int sum = 0;
    while (tail < numsSize)
    {
        sum += nums[tail];
        if (sum >= s)
        {
            while (sum - nums[head] >= s)
            {
                sum -= nums[head];
                head++;
            }
            if ((tail - head + 1) < minRet)
            {
                minRet = tail - head + 1;
            }
        }
        tail++;
    }
    return (sum < s) ? 0 : minRet;
}
int main()
{
    int s, n;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << minSubArrayLen(s, n) << endl;
    return 0;
}