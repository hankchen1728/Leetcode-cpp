#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dists(m, vector<int>(n, m + n + 1));

    // int currDist = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          dists[i][j] = 0;
        } else {
          // be careful with top and left bourdary
          if (i > 0) dists[i][j] = min(dists[i - 1][j] + 1, dists[i][j]);
          if (j > 0) dists[i][j] = min(dists[i][j - 1] + 1, dists[i][j]);
        }
      }
    }

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (dists[i][j] > 1) {
          if (i < m - 1) dists[i][j] = min(dists[i + 1][j] + 1, dists[i][j]);
          if (j < n - 1) dists[i][j] = min(dists[i][j + 1] + 1, dists[i][j]);
        }
      }
    }

    return dists;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<vector<int>>> testMats = {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
                                          {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}},
                                          {{0, 1, 1, 1, 0},
                                           {1, 1, 1, 1, 1},
                                           {0, 1, 0, 0, 0},
                                           {1, 1, 1, 1, 1},
                                           {1, 1, 0, 1, 1}}};
  size_t nTest = testMats.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "mat = " << int2dVectorToString(testMats[i]) << endl;
    // Call the Solution function here!
    vector<vector<int>> res = Solution().updateMatrix(testMats[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
