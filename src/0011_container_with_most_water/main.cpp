#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  // Solution() {
  //   // Speedup
  //   ios::sync_with_stdio(0);
  //   cin.tie(0);
  //   cout.tie(0);
  // }
  int maxArea(vector<int>& height) {
    int L = 0, R = height.size() - 1;
    int res = 0, h;

    while (L < R) {
      h = min(height[L], height[R]);
      res = max(res, h * (R - L));

      // height[L] < height[R] ? ++L : --R;

      // keep moving until the height is larger than current minimal one
      while (L < R && h >= height[L]) ++L;
      while (L < R && h >= height[R]) --R;
    }
    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testHeights = {
      {1, 8, 6, 2, 5, 4, 8, 3, 7},  // 49
      {1, 1},                       // 1
  };
  size_t nTest = testHeights.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "height = " << intVectorToString(testHeights[i]) << endl;
    // Call the Solution function here!
    int res = Solution().maxArea(testHeights[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
