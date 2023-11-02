#include <bits/stdc++.h>
using namespace std;

void fun(int i, int j, int &sum, int n, int index, string s) {
    if (i > 6 || i < 0 || j > 6 || j < 0 || index > n)
        return;
    if (index == n && i==6 && j==0) {
        sum++;
        return;
    }
    
    if (s[index] == '?') {
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if (nr >= 0 && nr < 7 && nc >= 0 && nc < 7) {
                fun(nr, nc, sum, n, index + 1, s);
            }
        }
    } else if (s[index] == 'U') {
        fun(i - 1, j, sum, n, index + 1, s);
    } else if (s[index] == 'D') {
        fun(i + 1, j, sum, n, index + 1, s);
    } else if (s[index] == 'L') {
        fun(i, j - 1, sum, n, index + 1, s);
    } else if (s[index] == 'R') {
        fun(i, j + 1, sum, n, index + 1, s);
    }
}

int main() {
    string s;
    cin >> s;
    int maxi = 0;
    int sum = 0;
    fun(0, 0, sum, s.length(), 0, s);

    cout << sum << endl;
    return 0;
}
