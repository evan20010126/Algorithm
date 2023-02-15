/* Conclusion: vector is pass-by-value */
#include <bits/stdc++.h>
using namespace std;

void exchange(vector<int>& vec, int i, int j) {
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

int main() {
    vector<int> vec{0, 1, 2};

    /* print */
    for (int i = 0; i < vec.size(); ++i) { cout << vec[i] << " "; }

    exchange(vec, 0, 1);

    /* print */
    for (int i = 0; i < vec.size(); ++i) { cout << vec[i] << " "; }

    return 0;
}