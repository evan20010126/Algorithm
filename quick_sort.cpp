#include <bits/stdc++.h>
using namespace std;

void exchange(vector<int>& vec, int i, int j) {
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

/* Divide */
int partition(vector<int>& vec, int l, int r) {
    int pivot_value = vec[r];
    int small_endidx = l - 1;
    for (int i = l; i < r; ++i) {
        if (vec[i] <= pivot_value) {
            ++small_endidx;
            exchange(vec, small_endidx, i);
        }
    }
    exchange(vec, small_endidx + 1, r);
    return small_endidx + 1;
}

void quick_sort(vector<int>& vec, int l, int r) {
    if (l < r) {
        // static int i = 0;
        int q = partition(vec, l, r);
        quick_sort(vec, l, q - 1);
        quick_sort(vec, q + 1, r);
    }
}

/* find k largest */
int randomized_select(vector<int>& vec, int l, int r, int target) {
    // if (l == r) { return vec[l]; }

    int q = partition(vec, l, r);
    int k = q - l + 1;

    if (target == k) {
        return vec[q];
    } else if (target < k) {
        return randomized_select(vec, l, q - 1, target);
    } else {
        return randomized_select(vec, q + 1, r, target - k);
    }
}

int main() {
    vector<int> vec{9, 8, 7, 6, 5, 4, 3, 2, 1};
    // quick_sort(vec, 0, vec.size() - 1);
    // for (auto i : vec) { cout << i << " "; }
    int target;
    cin >> target;
    cout << randomized_select(vec, 0, vec.size() - 1, target);
    return 0;
}
