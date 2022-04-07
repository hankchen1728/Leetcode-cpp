#include <iostream>
#include <map>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
#define LL long long

class Solution {
  long long int mod = 1e9 + 7;

 public:
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  int threeSumMulti(vector<int>& arr, int target) {
    map<int, int> cntMp;
    for (const int& n : arr) ++cntMp[n];

    // extract sorted unique number
    vector<int> uniqueNums;
    for (auto iter = cntMp.begin(); iter != cntMp.end(); ++iter) {
      uniqueNums.push_back(iter->first);
    }

    LL res = 0, occurs;
    int currNum, residual, twoSum, N = uniqueNums.size();
    int i, j, k;
    for (i = 0; i < N; ++i) {
      currNum = uniqueNums[i];
      if (currNum > target) break;

      residual = target - currNum;
      j = (cntMp[currNum] > 1) ? i : i + 1;
      k = N - 1;

      while (j <= k) {
        twoSum = uniqueNums[j] + uniqueNums[k];
        if (twoSum > residual) {
          --k;
        } else if (twoSum < residual) {
          ++j;
        } else {
          if (i == j && j == k) {
            occurs = ((LL)(cntMp[currNum] * (cntMp[currNum] - 1) / 2)) *
                     (LL)(cntMp[currNum] - 2) / 3;
          } else if (i == j) {
            occurs = ((LL)(cntMp[currNum] * (cntMp[currNum] - 1) / 2)) *
                     (LL)(cntMp[uniqueNums[k]]);
          } else if (j == k) {
            occurs =
                (LL)(cntMp[uniqueNums[k]] * (cntMp[uniqueNums[k]] - 1) / 2) *
                (LL)(cntMp[currNum]);
          } else {
            occurs = (LL)(cntMp[currNum] * cntMp[uniqueNums[j]]) *
                     (LL)(cntMp[uniqueNums[k]]);
          }
          res = (res + occurs) % mod;
          --k;
          ++j;
        }
      }
    }

    return (int)res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<vector<int>, int>> testCase = {
      {{1, 1, 2, 2, 3, 3, 4, 4, 5, 5}, 8},  // 20
      {{1, 1, 2, 2, 2, 2}, 5},              // 12
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i].first)
         << ", target = " << testCase[i].second << endl;
    // Call the Solution function here!
    int res = Solution().threeSumMulti(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
