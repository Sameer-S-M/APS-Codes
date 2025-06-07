// C++ Program to solve House Robber Problem using Memoization

#include <iostream>
#include <vector>
using namespace std;

int maxLootRec(const vector<int>& hval, int n, vector<int>& memo) {
  
    if (n <= 0) return 0;
    if (n == 1) return hval[0];

    // Check if the result is already computed
    if (memo[n] != -1) return memo[n];

    int pick = hval[n - 1] + maxLootRec(hval, n - 2, memo);
    int notPick = maxLootRec(hval, n - 1, memo);

    // Store the max of two choices in the memo array and return it
    memo[n] = max(pick, notPick);
    return memo[n];
}

int maxLoot(vector<int>& hval) {
    int n = hval.size();
  
    // Initialize memo array with -1
    vector<int> memo(n + 1, -1); 
    return maxLootRec(hval, n, memo);
}

int main() {
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    cout << maxLoot(hval);
    return 0;
}