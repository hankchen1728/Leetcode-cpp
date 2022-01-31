#include <iostream>
#include <numeric>
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
  int maximumWealth(vector<vector<int>>& accounts) {
    int maxSum = 0;
    for (vector<int>& acc : accounts) {
      int accSum = accumulate(acc.begin(), acc.end(), 0);
      maxSum = max(maxSum, accSum);
    }
    return maxSum;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<vector<int>>> testCase = {{{1, 2, 3}, {3, 2, 1}},
                                          {{1, 5}, {7, 3}, {3, 5}},
                                          {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "accounts = " << int2dVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().maximumWealth(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
