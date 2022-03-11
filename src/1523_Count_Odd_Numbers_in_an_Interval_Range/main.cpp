#include <iostream>
#include <utility>
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
  int countOdds(int low, int high) { return (high + 1) / 2 - low / 2; }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<int, int>> testCase = {
      {3, 7},   // 3
      {8, 10},  // 1
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m low = " << testCase[i].first
         << ", high = " << testCase[i].second << endl;
    // Call the Solution function here!
    int res = Solution().countOdds(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
