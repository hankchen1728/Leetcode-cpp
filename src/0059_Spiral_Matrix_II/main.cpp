#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  // Solution() {
  //   // Speed up
  //   ios::sync_with_stdio(false);
  //   cin.tie(nullptr);
  //   cout.tie(nullptr);
  // }
  vector<vector<int>> generateMatrix(int n) {
    int8_t edge_size = n - 1;
    int8_t c_x = 0, c_y = 0;
    vector<pair<int8_t, int8_t>> edge_direct = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int16_t val = 1;
    vector<vector<int>> mat(n, vector<int>(n));

    for (int8_t layer = n / 2; layer > 0; --layer) {
      for (const pair<int, int>& d : edge_direct) {
        int8_t e_s = edge_size;
        while (e_s-- > 0) {
          mat[c_x][c_y] = (int)val;

          // next cell
          c_x += d.first, c_y += d.second;
          ++val;
        }
      }

      // next layer
      c_x++, c_y++;
      edge_size -= 2;
    }

    // central grid for n is odd
    if (n % 2) mat[c_x][c_y] = val;

    return mat;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<int> testCase = {
      3,  // [[1,2,3],[8,9,4],[7,6,5]]
      1,  // [[1]]
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m n = " << testCase[i] << endl;
    // Call the Solution function here!
    vector<vector<int>> res = Solution().generateMatrix(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
