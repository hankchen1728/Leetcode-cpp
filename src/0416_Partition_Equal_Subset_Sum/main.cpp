#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>
#define BOOL2STR(res) (res ? "true" : "false")

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
  bool canPartition(vector<int>& nums) {
    int targetSum = accumulate(nums.begin(), nums.end(), 0);

    if (targetSum % 2) return false;
    targetSum /= 2;
    bitset<10001> bitmask(1);

    for (int& n : nums) bitmask = bitmask | bitmask << n;
    return bitmask[targetSum];
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {{1, 5, 11, 5}, {1, 2, 3, 5}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    bool res = Solution().canPartition(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << BOOL2STR(res) << endl;
    cout << "===========" << endl;
  }
}
