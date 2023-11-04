// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n,x;
    cin >> n >> x;
    set<int> pos;
    multiset<int> len;
    pos.insert(0);
    pos.insert(n);
    len.insert(n-0);
    for(int i=0;i<x;i++)
    {
        int num;
        cin >> num;
        pos.insert(num);
        auto it=pos.find(num);
        int pre=*prev(it);
        int nex=*next(it);
        len.erase(len.find(nex-pre));
        len.insert(num-pre);
        len.insert(nex-num);
        cout << *len.rbegin() << " ";
    }
    return 0;
}