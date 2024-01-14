#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    set<int> st;
    st.insert(0);

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int x : st)
            temp.push_back(x + arr[i]);

        for (int x : temp)
            st.insert(x);
    }

    cout << st.size() - 1 << endl;

    for (auto it = next(st.begin()); it != st.end(); ++it)
        cout << *it << " ";

    return 0;
}
