// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        arr.push_back(i+1);
    }
    while(arr.size()>1)
    {
        vector<int> left;
        for(int i=0;i<arr.size();i++)
        {
            if(i%2!=0)
            {
                cout << arr[i] << " ";
            }
            else
            {
                left.push_back(arr[i]);
            }
        }
        if(arr.size()%2==0)
            arr=left;
        else
        {
            int st=left.back();
            left.pop_back();
            arr.clear();
            arr.push_back(st);
            for(auto it:left)
                arr.push_back(it);
        }
    }
    cout << arr[0];
    return 0;
}
