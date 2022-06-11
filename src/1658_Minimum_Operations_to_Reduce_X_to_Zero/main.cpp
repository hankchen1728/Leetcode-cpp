#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution
{
 public:
  Solution()
  {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }

  int minOperations(vector<int>& nums, int x)
  {
    // target sum for maximum subarray
    int target = -x;
    for (int& n : nums) target += n;

    if (target == 0) return nums.size();

    int L = 0, N = nums.size(), maxLen = 0, subSum = 0;

    for (int R = 0; R < N; ++R)
    {
      subSum += nums[R];

      // move left pointer
      while (L <= R && subSum > target)
      {
        subSum -= nums[L];
        ++L;
      }

      if (subSum == target)
      {
        maxLen = max(maxLen, R - L + 1);
      }
    }

    return maxLen ? N - maxLen : -1;
  }
};
// Solution end

int main()
{
  cout << "\n===========" << endl;

  // Setting the test cases
  vector<pair<vector<int>, int>> testCase = {
      {{1, 1, 4, 2, 3}, 5},       // 2
      {{5, 6, 7, 8, 9}, 4},       // -1
      {{3, 2, 20, 1, 1, 3}, 10},  // 5
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++)
  {
    cout << Bold("Example " + to_string(i + 1) + ":") << endl;

    // print the test case input here!
    cout << Bold("Input:") << " nums = " << intVectorToString(testCase[i].first)
         << ", x = " << testCase[i].second << endl;

    // Call the Solution function here!
    int res = Solution().minOperations(testCase[i].first, testCase[i].second);
    cout << Bold("Output: ") << res << endl;

    cout << "===========" << endl;
  }
}
