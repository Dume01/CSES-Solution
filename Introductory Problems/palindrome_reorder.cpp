// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    string s;
    cin >> s;
    vector<int> freq(26,0);
    for(int i=0;i<s.length();i++)
    {
        freq[s[i]-'A']++;
    }
    int ev=0;
    int od=0;
    for(int i=0;i<26;i++)
    {
        if(freq[i]!=0 && freq[i]%2==0)
            ev++;
        if(freq[i]!=0 && freq[i]%2!=0)
            od++;
    }
    if(od>1)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    string w="";
    if(od==0)
    {
        for(int i=0;i<26;i++)
        {
             if(freq[i]!=0)
            {
                for(int j=0;j<freq[i]/2;j++)
                {
                    w+=(char)(i+'A');
                }
            }
        }
        for(int i=25;i>=0;i--)
        {
             if(freq[i]!=0)
            {
                for(int j=0;j<freq[i]/2;j++)
                {
                    w+=(char)(i+'A');
                }
            }
        }
    }
    else
    {   od=0;
        for(int i=0;i<26;i++)
        {
             if(freq[i]!=0 && freq[i]%2==0)
            {   
                for(int j=0;j<freq[i]/2;j++)
                {
                    w+=(char)(i+'A');
                }
            }
            else if(freq[i]!=0)
            {
                od=i;
            }
        }
        for(int j=0;j<freq[od];j++)
        {
            w+=(char)(od+'A');
        }
        for(int i=25;i>=0;i--)
        {
             if(freq[i]!=0 && freq[i]%2==0)
            {
                for(int j=0;j<freq[i]/2;j++)
                {
                    w+=(char)(i+'A');
                }
            }
        }
    }
    cout << w;
    
}