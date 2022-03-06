#include <iostream>
#include <tuple>
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
  double champagneTower(int poured, int query_row, int query_glass) {
    // initialize matrix for DP
    // array is much faster than std::vector
    double tower[2][query_glass + 2];
    memset(tower, 0, 2 * (query_glass + 2) * sizeof(double));

    tower[0][0] = (double)poured;

    for (int iRow = 0; iRow < query_row; ++iRow) {
      for (int iCol = 0; iCol <= min(iRow, query_glass); ++iCol) {
        if (tower[iRow % 2][iCol] > 1) {
          double fall = (tower[iRow % 2][iCol] - 1) / 2;
          tower[(iRow + 1) % 2][iCol] += fall;
          tower[(iRow + 1) % 2][iCol + 1] += fall;
        }

        tower[iRow % 2][iCol] = 0;
      }
    }

    return min((double)1, tower[query_row % 2][query_glass]);
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<tuple<int, int, int>> testCase = {
      {1, 1, 1},            // 0
      {2, 1, 1},            // 1
      {100000009, 33, 17},  // 0.5
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input: \e[0m ";
    printf("poured = %d, query_row = %d, query_glass = %d\n",
           get<0>(testCase[i]), get<1>(testCase[i]), get<2>(testCase[i]));
    // Call the Solution function here!
    double res = Solution().champagneTower(
        get<0>(testCase[i]), get<1>(testCase[i]), get<2>(testCase[i]));
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
