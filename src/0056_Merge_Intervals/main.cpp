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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    int L = intervals[0][0], R = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] > R) {
        res.push_back({L, R});
        L = intervals[i][0];
        R = intervals[i][1];
      } else {
        if (intervals[i][1] > R) R = intervals[i][1];
      }
    }
    res.push_back({L, R});

    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<vector<int>>> testIntervals = {
      {{1, 3}, {2, 6}, {8, 10}, {15, 18}},
      {{1, 4}, {4, 5}},
      {{1, 5}, {1, 2}, {2, 5}},
  };
  size_t nTest = testIntervals.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m intervals = " << int2dVectorToString(testIntervals[i])
         << endl;
    // Call the Solution function here!
    vector<vector<int>> res = Solution().merge(testIntervals[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
