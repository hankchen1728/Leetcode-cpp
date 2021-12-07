#include <cstring>
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
  int minCostToMoveChips(vector<int>& position) {
    int numSum[2];
    memset(numSum, 0, sizeof(numSum));

    for (int& n : position) numSum[n % 2]++;

    return min(numSum[0], numSum[1]);
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {{1, 2, 3}, {2, 2, 2, 3, 3}, {1, 1000000000}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m position = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().minCostToMoveChips(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
