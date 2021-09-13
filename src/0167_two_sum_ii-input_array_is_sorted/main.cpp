#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> pair(2, 1);
    int l = 0, r = numbers.size() - 1;

    while (l < r) {
      if (numbers[l] + numbers[r] > target) {
        r--;
      } else if (numbers[l] + numbers[r] < target) {
        l++;
      } else {
        pair[0] = l+1; pair[1] = r+1;
        return pair;
      }
    }
    return pair;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {{2, 7, 11, 15}, {2, 3, 4}, {-1, 0}};
  vector<int> testTargets = {9, 6, -1};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
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
