#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution
{
 public:
  vector<int> twoSum(vector<int>& numbers, int target)
  {
    int16_t L = 0, R = numbers.size() - 1;
    int pairSum;

    while (L < R)
    {
      pairSum = numbers[L] + numbers[R];

      if (pairSum > target)
        --R;
      else if (pairSum < target)
        ++L;
      else
        break;
    }

    return {L + 1, R + 1};
  }
};
// Solution end

int main()
{
  // Write something here
  vector<vector<int>> testNums = {{2, 7, 11, 15}, {2, 3, 4}, {-1, 0}};
  vector<int> testTargets = {9, 6, -1};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++)
  {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "numbers = " << intVectorToString(testNums[i])
         << ", target = " << testTargets[i] << endl;
    // Call the Solution function here!
    vector<int> pair = Solution().twoSum(testNums[i], testTargets[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(pair) << endl;
    cout << "===========" << endl;
  }
}
