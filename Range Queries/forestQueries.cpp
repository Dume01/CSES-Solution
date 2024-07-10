#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    
    // Input forest map and construct the grid with tree counts
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char in;
            cin >> in;
            if (in == '*')
                grid[i][j] = 1;
        }
    }

    // Compute prefix sums for the grid
    vector<vector<int>> prefixSum(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prefixSum[i][j] = grid[i][j];
            if (i > 0) prefixSum[i][j] += prefixSum[i - 1][j];
            if (j > 0) prefixSum[i][j] += prefixSum[i][j - 1];
            if (i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i - 1][j - 1];
        }
    }

    // Process each query
    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--; // Convert to 0-based indexing
        
        int result = prefixSum[y2][x2];
        if (y1 > 0) result -= prefixSum[y1 - 1][x2];
        if (x1 > 0) result -= prefixSum[y2][x1 - 1];
        if (y1 > 0 && x1 > 0) result += prefixSum[y1 - 1][x1 - 1];
        
        cout << result << endl;
    }

    return 0;
}
