#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

int main()
{
    string str_1, str_2;
    cin >> str_1 >> str_2;
    arr.resize(str_1.size(), 0);
    int k, t;
    for (int i = 0; i < str_2.size(); i++)
    {
        k = 0;
        for (int j = 0; j < str_1.size(); j++)
        {
            t = arr[j];
            if (str_2[i] == str_1[j])
            {
                arr[j] = max(arr[j], k + 1);
            }
            arr[j] = max(arr[j], k);
            k = max(k, t);
        }
    }

        cout << arr[str_1.size() - 1] << endl;
    return 0;
}