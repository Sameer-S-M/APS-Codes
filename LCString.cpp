#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Returns length of longest common substring of 
// s1[0..m-1] and s2[0..n-1]
int maxCommStr(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a table to store lengths of longest
    // common suffixes of substrings.
    vector<vector<int>> LCSuf(m + 1, vector<int>(n + 1, 0));

    // Build LCSuf[m+1][n+1] in bottom-up fashion.    
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                LCSuf[i][j] = LCSuf[i - 1][j - 1] + 1;
                res = max(res, LCSuf[i][j]);
            } else {
                LCSuf[i][j] = 0;
            }
        }
    }
    return res;
}

int main() {
    string s1 = "geeksforgeeks";
    string s2 = "ggeegeeksquizpractice";
    cout << maxCommStr(s1, s2) << endl;
    return 0;
}