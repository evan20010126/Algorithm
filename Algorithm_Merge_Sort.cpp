// 2021/03/24 Merge_SOrt
// reference: https://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html
//            https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=57043

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void Merge_Sort(int arr[], int front, int end);
void Merge(int arr[], int, int, int);

int main()
{
    int input;
    vector<int> temp;
    while (cin >> input)
    {
        temp.push_back(input);
    }
    int arr[temp.size()];
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    Merge_Sort(arr, 0, temp.size() - 1);
    for (int i = 0; i < temp.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void Merge_Sort(int arr[], int front, int end) // this function mainly means -> 拆front~midlle的index、拆middle+1~end的index
{
    if (front < end)
    {
        int middle = (front + end) / 2;
        Merge_Sort(arr, front, middle);   // last step return sorted left arr
        Merge_Sort(arr, middle + 1, end); // last step return sorted right arr
        Merge(arr, front, middle, end);
    }
}

void Merge(int arr[], int front, int middle, int end)
{
    int left_arr_item_num = (middle - front + 1) + 1;      // add additionally 1 because infinite
    int right_arr_item_num = (end - (middle + 1) + 1) + 1; // add additionally 1 because infinite
    int left_arr[left_arr_item_num];
    int right_arr[right_arr_item_num];
    /*construct left_arr and right_arr*/
    /*Start*/
    int i;
    int j = 0;
    // cout << front << " " << middle;
    for (i = front; i <= middle; i++) // front middle end are index (aren't amount) -> needs '='
    {
        left_arr[j] = arr[i];
        j++;
    }
    left_arr[j] = INT_MAX;
    j = 0;

    for (; i <= end; i++)
    {
        right_arr[j] = arr[i];
        j++;
    }
    right_arr[j] = INT_MAX;
    /*End*/
    /*left_arr and right_arr sort to arr(all)*/
    int left_ptr = 0;
    int right_ptr = 0;
    i = front;
    while (i <= end)
    {
        if (left_arr[left_ptr] <= right_arr[right_ptr]) // left <= right //上課: 第一名在右邊
        {
            arr[i] = left_arr[left_ptr];
            left_ptr++;
        }
        else
        {
            arr[i] = right_arr[right_ptr];
            right_ptr++;
        }
        i++;
    }
}