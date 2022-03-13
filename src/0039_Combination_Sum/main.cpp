#include <algorithm>
#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
  vector<vector<int>> res;
  vector<int> _candidates;

 public:
  /*
  Solution() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  */
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    _candidates = candidates;
    sort(_candidates.begin(), _candidates.end());

    vector<int> comb;
    backtracking(comb, target, 0);
    return res;
  }

  void backtracking(vector<int>& comb, int target, int idxCurr) {
    if (target == 0) {
      res.push_back(comb);
      return;
    }

    // ran out of all candidates
    if (idxCurr >= _candidates.size()) return;

    target -= _candidates[idxCurr];
    if (target < 0) return;

    // keep adding current number
    comb.push_back(_candidates[idxCurr]);
    backtracking(comb, target, idxCurr);
    comb.pop_back();

    // jump to next number
    target += _candidates[idxCurr];
    backtracking(comb, target, idxCurr + 1);
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<vector<int>, int>> testCase = {
      {{2, 3, 6, 7}, 7},  // [[2,2,3],[7]]
      {{2, 3, 5}, 8},     // [[2,2,2,2],[2,3,3],[3,5]]
      {{2}, 1},           // []
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m candidates = " << intVectorToString(testCase[i].first)
         << ", target = " << testCase[i].second << endl;
    // Call the Solution function here!
    vector<vector<int>> res =
        Solution().combinationSum(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
