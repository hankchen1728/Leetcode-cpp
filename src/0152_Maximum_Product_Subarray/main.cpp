#include <algorithm>
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
  int maxProduct(vector<int>& nums) {
    int subMax = 1, subMin = 1, maxProd = INT_MIN, currMax, currMin;

    for (int& n : nums) {
      currMax = max({subMax * n, n, subMin * n});
      currMin = min({subMax * n, n, subMin * n});
      subMax = currMax;
      subMin = currMin;
      maxProd = max(subMax, maxProd);
    }

    return maxProd;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testNums = {
      {2, 3, -2, 4}, {-2, 0, -1}, {-2, 2, 3, -2, 4, -3, 1, 0, 3}};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    int res = Solution().maxProduct(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
