#include <iostream>
#include <vector>
using namespace std;

int *merge_sort(int *arr, int left, int right)
{
    int *return_arr = new int[right - left + 1];
    if (left == right)
    {
        *(return_arr) = *(arr + left);
        return return_arr;
    }
    else
    {

        int middle = (left + right) / 2;
        int *arr_l = merge_sort(arr, left, middle);
        int *arr_r = merge_sort(arr, middle + 1, right);
        int i = 0; // index: 0 ~ middle - left
        int j = 0; // index: 0 ~ right - (middle + 1)
        int k = 0;

        while (true)
        {
            if (i > middle - left || j > right - (middle + 1))
            {
                break;
            }
            else
            {
                if (*(arr_l + i) < *(arr_r + j))
                {
                    *(return_arr + k) = *(arr_l + i);
                    i++;
                    k++;
                }
                else
                {
                    *(return_arr + k) = *(arr_r + j);
                    j++;
                    k++;
                }
            }
        }
        while (i <= middle - left)
        {
            *(return_arr + k) = *(arr_l + i);
            i++;
            k++;
        }
        while (j <= right - (middle + 1))
        {
            *(return_arr + k) = *(arr_r + j);
            j++;
            k++;
        }
        return return_arr;
    }
}

int main()
{
    int size = 0;
    int *arr = new int[50000];
    while (cin >> *(arr + size))
        size++;
    int *answer = merge_sort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << *(answer + i) << " ";
    }
    return 0;
}