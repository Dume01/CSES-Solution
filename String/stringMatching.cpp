#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(string txt, string pat) {
    int N = txt.size();
    int M = pat.size();
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    int cnt = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == M) {
            cnt++;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return cnt;
}

int main() {
    string n, m;
    cin >> n >> m;
    cout << KMPSearch(n, m) << endl;
    return 0;
}
