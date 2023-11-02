// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    long long sum1=0;
    long long sum=0;
    if((n+1)%2==0)
    {
        sum1=(n+1)/2;
        sum=n*sum1;
    }
    if((n)%2==0)
    {
        sum1=(n)/2;
        sum=(n+1)*sum1;
    }
    
    if(sum%2!=0)
    {
        cout << "NO";
        return 0;
    }
    sum=sum/2;
    long long temp=sum;
    vector<int> st1(n+3,0);
    int i=1;
    int c=1;
    vector<int> ans;
    if(n%2!=0)
    {
        while(i<=n && sum>0)
        {
            ans.push_back(i);
            st1[i]=1;
            sum-=i;
            if(c%2!=0)
                i+=1;
            else
                i=i+3;
            c++;
        }
    }
    else
    {   
    
        while(i<=n && sum>0)
        {
            ans.push_back(i);
            st1[i]=1;
            sum-=i;
            if(c%2!=0)
                i+=3;
            else
                i=i+1;
            c++;
        }
        
    }
    if(sum!=0)
    {   
        cout <<"NO"<<endl;
        return 0;
    }
    vector<int> ans2;
    long long sumx=0;
    for(int i=1;i<=n;i++)
    {
        if(st1[i]==0)
        {
            ans2.push_back(i);
            sumx+=i;
        }
    }
    
    if(sumx!=temp)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" <<endl;
    cout << ans.size() << endl;
    for(auto it:ans)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << ans2.size() << endl;
    int x=0;
    for(auto it:ans2)
    {   
        cout << it << " ";
    }
 
    return 0;
}
