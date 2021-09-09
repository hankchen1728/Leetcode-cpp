#include <algorithm>
#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  Solution() {
    // Speedup
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int maxArea(vector<int>& height) {
    if (height.size() == 2) return min(height[0], height[1]);
    int left = 0, right = height.size() - 1;

    int area = 0;
    while (left < right) {
      area = max(area, min(height[left], height[right]) * (right - left));
      if (height[left] <= height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return area;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testHeights = {{1, 8, 6, 2, 5, 4, 8, 3, 7},
                                     {1, 1},
                                     {4, 3, 2, 1, 4},
                                     {1, 2, 1},
                                     {1, 8, 6, 2, 5, 4, 8, 25, 7},
                                     {1, 3, 2, 5, 25, 24, 5}};
  size_t nTest = testHeights.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "height = " << intVectorToString(testHeights[i]) << endl;
    // Call the Solution function here!
    int ans = Solution().maxArea(testHeights[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
