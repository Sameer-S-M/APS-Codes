// Cpp program for Pascal’s Triangle Using Dynamic 
// Programming in O(n^2) time and O(n^2) extra space 

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printPascal(int n) {
    
    // An auxiliary array to store 
    // generated pascal triangle values
    vector<vector<int>> mat;

    // Iterate through every line and 
    // print integer(s) in it
    for (int row = 0; row < n; row++) {
      
        // Every line has number of integers 
        // equal to line number
      	vector<int>arr;
        for (int i = 0; i <= row; i++) {
          
        // First and last values in every row are 1
        if (row == i || i == 0)
            arr.push_back(1);
          
        // Other values are sum of values just 
        // above and left of above
        else
            arr.push_back(mat[row - 1][i - 1] + 
                            mat[row - 1][i]);
        }
        mat.push_back(arr);
    }
  return mat;
}

int main() {
    int n = 5;
    vector<vector<int>> mat = printPascal(n);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            	cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}