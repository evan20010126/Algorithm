#include <iostream>
using namespace std;

int main()
{
    int test_times;
    cin >> test_times;

    for (int i = 0; i < test_times; i++)
    {
        int depth, nth_ball, pos = 1;
        cin >> depth >> nth_ball;
        for (int j = 0; j < depth - 1; j++)
        {
            if (nth_ball % 2 == 0)
            {
                pos = pos * 2 + 1; //right
            }
            else
            {
                pos = pos * 2; //left
            }
            if (nth_ball > 1)
            {
                if (nth_ball % 2 == 0)
                {
                    nth_ball /= 2;
                }
                else
                {
                    nth_ball = nth_ball / 2 + 1;
                }
            }
        }
        cout << pos << endl;
    }
    int stop;
    cin >> stop;

    return 0;
}