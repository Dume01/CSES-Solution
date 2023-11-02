#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    string s;
    cin >> s;
    int cnt=1;
    int maxi=0;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==s[i-1])
            cnt++;
        else
        {
            maxi=max(maxi,cnt);
            cnt=1;
        }
    }
    maxi=max(maxi,cnt);
    cout << maxi;
}