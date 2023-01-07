#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;
/*-------------*/
template <class T>
struct Abs
{
    T operator()(const T &a)
    {
        if (a < 0)
        {
            return a * -1;
        }
        else
        {
            return a;
        }
    }
};
template <class S, class T, class I, class F>
int inner_product(S a_start, S a_end, T b_start, I sum, F fn)
{
    int ans = 0;
    vector<int>::iterator i = a_start;
    list<int>::iterator j = b_start;

    for (; i != a_end; i++, j++)
    {
        ans += fn(*i * *j);
    }
    return ans;
}
/*-------------*/
int main()
{ //請勿更動main()函式的程式碼

    vector<int> a;
    list<int> b;
    int input, sum = 0;

    cin >> input; //將元素輸入至容器vector,list中
    for (int i = 0; i < input; i++)
    {
        int element;
        cin >> element;
        a.push_back(element);
    }
    for (int i = 0; i < input; i++)
    {
        int element;
        cin >> element;
        b.push_back(element);
    }
    //輸出兩個容器元素的絕對值乘積和
    cout << "The absolute inner product of a and b = "
         << inner_product(a.begin(), a.end(),
                          b.begin(), sum, Abs<int>())
         << endl;
    //Abs<int>()可看成Abs結構/類別中的運算子()覆載
    return 0;
}