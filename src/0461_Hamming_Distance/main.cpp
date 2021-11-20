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
  int hammingDistance(int x, int y) {
      int bitDiff = x ^ y, cnt = 0;
      while (bitDiff > 0) {
        // if (bitDiff & 1) cnt++; bitDiff >>= 1;

        // Remove the rightmost bit
        bitDiff &= bitDiff - 1;
        cnt++;
      }
      return cnt;
  }
};
// Solution end

int main() {
  // setting the test cases
  vector<pair<int, int>> testXY = {{1, 4}, {3, 1}};
  size_t nTest = testXY.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;

    cout << "Input:"
         << "\e[0m x = " << testXY[i].first << ", y = " << testXY[i].second
         << endl;
    // Call the Solution function here!
    int res = Solution().hammingDistance(testXY[i].first, testXY[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
