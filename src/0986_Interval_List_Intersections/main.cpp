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
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    vector<vector<int>> res;
    int lenA = firstList.size(), lenB = secondList.size(), iA = 0, iB = 0;

    while (iA < lenA && iB < lenB) {
      // check if intersect
      if (min(firstList[iA][1], secondList[iB][1]) >=
          max(firstList[iA][0], secondList[iB][0])) {
        res.push_back({max(firstList[iA][0], secondList[iB][0]),
                       min(firstList[iA][1], secondList[iB][1])});
      }

      // move to next interval
      if (firstList[iA][1] > secondList[iB][1]) {
        iB++;
      } else if (firstList[iA][1] < secondList[iB][1]) {
        iA++;
      } else {
        iA++; iB++;
      }
    }

    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<vector<vector<int>>, vector<vector<int>>>> testCase = {
      {{{0, 2}, {5, 10}, {13, 23}, {24, 25}},
       {{1, 5}, {8, 12}, {15, 24}, {25, 26}}},
      {{{1, 3}, {5, 9}}, {}},
      {{}, {{4, 8}, {10, 12}}},
      {{{1, 7}}, {{3, 10}}}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m firstList = " << int2dVectorToString(testCase[i].first)
         << ", secondList = " << int2dVectorToString(testCase[i].second)
         << endl;
    // Call the Solution function here!
    vector<vector<int>> res =
        Solution().intervalIntersection(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
