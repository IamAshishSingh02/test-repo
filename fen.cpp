#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int>& arr) {
        n = arr.size();
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            update(i, arr[i]);
    }

    void update(int idx, int val) {
        idx++; // 1-based index
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int prefixSum(int idx) {
        idx++; // 1-based index
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    int rangeSum(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    FenwickTree ft(arr);

    cout << "Sum (1,3): " << ft.rangeSum(1, 3) << endl;

    ft.update(1, 7); // add 7 at index 1
    cout << "After update Sum (1,3): " << ft.rangeSum(1, 3) << endl;

    return 0;
}