#include <bits/stdc++.h>
using namespace std;

typedef long long int long_long;

void build(int i, int low, int high, vector<long_long> &arr, vector<long_long> &seg) {
    if (low == high) {
        seg[i] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * i + 1, low, mid, arr, seg);
    build(2 * i + 2, mid + 1, high, arr, seg);

    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}

long_long query(int ind, int low, int high, int l, int r, vector<long_long> &seg) {
    if (low >= l && high <= r) {
        return seg[ind];
    }
    if (low > r || high < l) {
        return 0;
    }
    int mid = (low + high) / 2;
    long_long left = query(ind * 2 + 1, low, mid, l, r, seg);
    long_long right = query(ind * 2 + 2, mid + 1, high, l, r, seg);

    return left + right;
}

void update(int ind, int low, int high, int i, long_long val, vector<long_long> &seg) {
    if (low == high) {
        seg[ind] = val;
        return;
    }
    int mid = (low + high) / 2;

    if (i <= mid)
        update(ind * 2 + 1, low, mid, i, val, seg);
    else
        update(ind * 2 + 2, mid + 1, high, i, val, seg);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<long_long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<long_long> seg(4 * n, 0);

    build(0, 0, n - 1, arr, seg);

    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 2) {
            b--; c--;
            cout << query(0, 0, n - 1, b, c, seg) << endl;
        } else {
            b--;
            update(0, 0, n - 1, b, c, seg);
        }
    }
}
