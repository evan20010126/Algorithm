#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input1;
    string input2;
    cin >> input1;
    cin >> input2;
    input1 = "x" + input1;
    input2 = "y" + input2;

    int c[input1.size()][input2.size()];
    int m = input1.size();
    int n = input2.size();
    for (int i = 0; i < m; i++)
        c[i][0] = 0;
    for (int j = 0; j < n; j++)
        c[0][j] = 0;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (input1[i] == input2[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
            }
            else
            {
                c[i][j] = c[i][j - 1];
            }
        }
    }
    cout << c[input1.size() - 1][input2.size() - 1] << endl;
    return 0;
}