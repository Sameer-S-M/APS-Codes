#include <bits/stdc++.h>
using namespace std;

// Fills lookup array lookup[][] in bottom up manner.
vector<vector<int>> buildSparseTable(vector<int> &arr) {
    int n = arr.size();

    // create the 2d table
    vector<vector<int>> lookup(n + 1,
                vector<int>(log2(n) + 1));

    // Initialize for the intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];

    // Compute values from smaller to bigger intervals
    for (int j = 1; (1 << j) <= n; j++) {

        // Compute minimum value for all intervals with
        // size 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {

            if (lookup[i][j - 1] < 
                lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = 
                lookup[i + (1 << (j - 1))][j - 1];
        }
    }

    return lookup;
}

// Returns minimum of arr[L..R]
int query(int L, int R, vector<vector<int>> &lookup)  {

    // Find highest power of 2 that is smaller
    // than or equal to count of elements in range
    int j = (int)log2(R - L + 1);

    // Compute minimum of last 2^j elements with first
    // 2^j elements in range.
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];
    else
        return lookup[R - (1 << j) + 1][j];
}

vector<int> solveQueries(vector<int>& arr, 
                vector<vector<int>>& queries) {
    int n = arr.size();
    int m = queries.size();
    vector<int> result(m);
    
    // Build the sparse table
    vector<vector<int>> lookup = buildSparseTable(arr);
    
    // Process each query
    for (int i = 0; i < m; i++) {
        int L = queries[i][0];
        int R = queries[i][1];
        result[i] = query(L, R, lookup);
    }
    
    return result;
}

int main() {
    vector<int> arr = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
    vector<vector<int>> queries = { {0, 4}, {4, 7}, {7, 8} };
    vector<int> res = solveQueries(arr, queries);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}