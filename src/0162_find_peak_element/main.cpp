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
  // method 1: O(nlogn)
  int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1, mid = right;
    while (left < right) {
      mid = (left + right) / 2;
      if (nums[mid] > nums[mid + 1]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return right;
  }
  // method 2: O(n)
  int findPeakElement_slow(vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; i++) {
      if (nums[i] > nums[i + 1]) return i;
    }
    return len - 1;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testCase = {{1, 2, 3, 1}, {1, 2, 1, 3, 5, 6, 4}, {1}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().findPeakElement(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
