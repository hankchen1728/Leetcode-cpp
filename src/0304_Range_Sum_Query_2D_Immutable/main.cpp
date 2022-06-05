#include <iostream>
#include <sstream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class NumMatrix {
 private:
  vector<vector<int>> _dp;

 public:
  NumMatrix(vector<vector<int>>& mat) {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint8_t M = mat.size(), N = mat[0].size();
    _dp.resize(M + 1, vector<int>(N + 1, 0));

    for (uint8_t i = 1; i <= M; ++i) {
      for (uint8_t j = 1; j <= N; ++j) {
        _dp[i][j] = mat[i - 1][j - 1] + _dp[i - 1][j] + _dp[i][j - 1] - _dp[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return _dp[row2 + 1][col2 + 1] - _dp[row2 + 1][col1] - _dp[row1][col2 + 1] + _dp[row1][col1];
  }
};
// Solution end

int main() {
  // Setup the test cases
  vector<string> ops{"NumMatrix", "sumRegion", "sumRegion", "sumRegion"};

  vector<vector<int>> matrix{{{3, 0, 1, 4, 2},
                              {5, 6, 3, 2, 1},
                              {1, 2, 0, 1, 5},
                              {4, 1, 0, 1, 7},
                              {1, 0, 3, 0, 5}}};

  vector<vector<int>> sumRegions{{2, 1, 4, 3}, {1, 1, 2, 2}, {1, 2, 2, 4}};

  cout << Bold("Input") << endl;
  cout << stringVectorToString(ops) << endl;
  cout << "[[" << int2dVectorToString(matrix) << "], "
       << int2dVectorToString(sumRegions).substr(1) << endl;

  // run testcase
  NumMatrix* obj = new NumMatrix(matrix);

  stringstream ss;
  ss << "[null, ";

  for (int i = 0; i < sumRegions.size(); ++i) {
    vector<int> reg = sumRegions[i];
    ss << obj->sumRegion(reg[0], reg[1], reg[2], reg[3]);
    if (i + 1 < sumRegions.size()) ss << ", ";
  }
  ss << "]";

  cout << Bold("Output") << endl;
  cout << ss.str() << endl;
  cout << "===========" << endl;
}
