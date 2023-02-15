#include <bits/stdc++.h>
using namespace std;

pair<int, int> find_max_and_min(vector<int> vec) {
    int global_max = INT_MIN, global_min = INT_MAX;
    int local_max, local_min;
    for (int i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] < vec[i + 1]) {
            local_max = vec[i + 1];
            local_min = vec[i];
        } else {
            local_max = vec[i];
            local_min = vec[i + 1];
        }
        global_max = max(global_max, local_max);
        global_min = min(global_min, local_min);
    }
    return {global_min, global_max};
}

int main() {
    vector<int> vec;
    return 0;
}
