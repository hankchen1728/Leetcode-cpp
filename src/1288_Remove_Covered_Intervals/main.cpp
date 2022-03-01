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
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int N = intervals.size(), rem = N;
    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& a, const vector<int>& b) {
           return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
         });

    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (intervals[i][1] <= intervals[j][1]) {
          --rem;
          break;
        }
      }
    }
    return rem;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<vector<int>>> testCase = {
      {{1, 4}, {3, 6}, {2, 8}}, {{1, 4}, {2, 3}}, {{1, 2}, {1, 4}, {3, 4}}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m intervals = " << int2dVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().removeCoveredIntervals(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
