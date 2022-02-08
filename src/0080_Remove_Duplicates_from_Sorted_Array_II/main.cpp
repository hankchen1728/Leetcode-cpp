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
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();

    int k = 2;  // left pointer (slower one)
    int R = 2;  // right pointer (faster one)
    for (; R < nums.size(); R++) {
      if (nums[R] > nums[k - 2]) {
        nums[k++] = nums[R];
      }
    }
    return k;
  }

  int _removeDuplicates(vector<int>& nums) {
    int L = 0, R = 0, nRepeat, nMove;
    while (R < nums.size()) {
      nRepeat = 0;
      while (R + 1 < nums.size() && nums[R] == nums[R + 1]) {
        nRepeat++;
        R++;
      }

      nMove = min(2, nRepeat + 1);
      if (R - L == nRepeat) {
        // R and L are in the same block of same elements
        L += nMove;
      } else {
        // at most twice in-place operation
        for (int i = 0; i < nMove; i++) {
          nums[L++] = nums[R];
        }
      }
      R++;
    }
    return L;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {{1, 1, 1, 2, 2, 3},
                                  {0, 0, 1, 1, 1, 1, 2, 3, 3}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int k = Solution().removeDuplicates(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << k << ", nums = " << intVectorToString(testCase[i])
         << endl;
    cout << "===========" << endl;
  }
}
