#include <bits/stdc++.h>
using namespace std;

void build(int ind, int low, int high, vector<int> &arr, vector<int> &seg) {
    if (low == high) {
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    
    build(2 * ind + 1, low, mid, arr, seg);
    build(2 * ind + 2, mid + 1, high, arr, seg);
    
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int val, vector<int> &seg) { 
    if (seg[ind] < val) {
        return -1; // No valid index
    }
    if (low == high) {
        return low;
    } 
    int mid = (low + high) / 2;
    int leftQuery = query(2 * ind + 1, low, mid, val, seg);
    if (leftQuery != -1) {
        return leftQuery;
    } 
    return query(2 * ind + 2, mid + 1, high, val, seg);
}

void update(int ind, int low, int high, vector<int> &seg, int val, int i) {
    if (low == high) {
        seg[ind] = val;
        return;
    }
    int mid = (low + high) / 2;
  
    if (i <= mid) {
        update(ind * 2 + 1, low, mid, seg, val, i);
    } else {
        update(ind * 2 + 2, mid + 1, high, seg, val, i);
    }
  
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> seg(4 * n);
    build(0, 0, n - 1, arr, seg);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        int index = query(0, 0, n - 1, a, seg);
        if (index == -1) {
            cout << 0 << endl;
        } else {
            cout << (index + 1) << endl;
            arr[index] -= a;
            update(0, 0, n - 1, seg, arr[index], index);
        }
    }
    return 0;
}
