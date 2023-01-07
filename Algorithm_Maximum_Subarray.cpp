#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void FIND_MAXIMUM_SUBARRAY(vector<int> *vec);
void FIND_MAX_CROSSING_SUBARRAY(vector<int> *vec);

int main()
{
    int temp;
    vector<int> vec;
    while (cin >> temp)
    {
        vec.push_back(temp);
    }
    //vec[vec.size()] = 0;                //this is low index
    //vec[vec.size()+1] = (vec.size() - 1)/2; //this is mid index
    //vec[vec.size()+2] = vec.size() - 1;   //this is high index
    vec.push_back(0);                    // vec.size()  ->left
    vec.push_back((vec.size() - 1) / 2); // vec.size()+1->mid
    vec.push_back(vec.size() - 1);       // vec.size()+2->right
    vec.push_back(INT_MIN);              //left-sum               // vec.size()+3->left-sum
    vec.push_back(INT_MIN);              //right_sum              // vec.size()+4->right-sum
    vec.push_back(INT_MIN);              //cross_sum              // vec.size()+5->cross-sum

    FIND_MAXIMUM_SUBARRAY(&vec);

    if (vec[vec.size() + 3] >= vec[vec.size() + 4] && vec[vec.size() + 3] >= vec[vec.size() + 5])
    {
        cout << vec[vec.size() + 3];
    }
    else if (vec[vec.size() + 4] >= vec[vec.size() + 3] && vec[vec.size() + 4] >= vec[vec.size() + 5])
    {
        cout << vec[vec.size() + 4];
    }
    else
    {
        cout << vec[vec.size() + 5];
    }
    return 0;
}

void FIND_MAXIMUM_SUBARRAY(vector<int> *vec)
{
    int low = (*vec)[(*vec).size()];
    int high = (*vec)[(*vec).size() + 2];

    if (high == low)
    {
        return;
    }
    else
    {
        int mid = (high - low) / 2;
        (*vec)[(*vec).size()] = low;
        (*vec)[(*vec).size() + 2] = mid;
        FIND_MAXIMUM_SUBARRAY(vec);
        (*vec)[(*vec).size()] = mid + 1;
        (*vec)[(*vec).size() + 2] = high;
        FIND_MAXIMUM_SUBARRAY(vec);
        (*vec)[(*vec).size()] = low;
        (*vec)[(*vec).size() + 1] = mid;
        (*vec)[(*vec).size() + 2] = high;
        FIND_MAXIMUM_SUBARRAY(vec);
    }

    // if ((*vec)[(*vec).size() + 3] >= (*vec)[(*vec).size() + 4] && (*vec)[(*vec).size() + 3] >= (*vec)[(*vec).size() + 5])
    // {
    //     //return left-low
    // }
    // else if ((*vec)[(*vec).size() + 4] >= (*vec)[(*vec).size() + 3] && (*vec)[(*vec).size() + 4] >= (*vec)[(*vec).size() + 5]){

    // }else{

    // }

    //好像直接改值根本不用return
}

void FIND_MAX_CROSSING_SUBARRAY(vector<int> *vec)
{
    (*vec)[(*vec).size() + 3] = INT_MIN;
    int sum = 0;
    for (int i = (*vec)[(*vec).size() + 1]; i >= (*vec)[(*vec).size()]; i++)
    {
        sum = sum + (*vec)[i];
        if (sum > (*vec)[(*vec).size() + 1])
        {
            (*vec)[(*vec).size() + 1] = sum;
        }
    }
    (*vec)[(*vec).size() + 2] = INT_MIN;
    sum = 0;
    for (int j = (*vec)[(*vec).size() + 1] + 1; j <= (*vec)[(*vec).size() + 2]; j++)
    {
        sum = sum + (*vec)[j];
        if (sum > (*vec)[(*vec).size() + 4])
        {
            (*vec)[(*vec).size() + 4] = sum;
        }
    }
}
