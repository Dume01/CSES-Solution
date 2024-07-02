#include <bits/stdc++.h>
using namespace std;

void calculateDivisors(long long numDivisors[])
{
    for (int i = 1; i < 1000005; i++) {
        for (int j = i; j < 1000005; j += i) {
            numDivisors[j]++;
        }
    }
}

int main()
{

    long long numDivisors[1000005] = {};
    calculateDivisors(numDivisors);

    int n;
    cin >> n;
    
    for(int i=0; i < n; i++) {
        
        int num;
        cin >> num;
        cout << numDivisors[num] << endl;
    }
}
