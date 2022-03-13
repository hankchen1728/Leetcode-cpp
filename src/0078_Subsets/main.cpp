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

  vector<vector<int>> subsets(vector<int>& nums) {
    return _subsets_Cascading(nums);
  }

  vector<vector<int>> _subsets_Cascading(vector<int>& nums) {
    int N = nums.size(), nSubset = 1, iSubset = 1;
    vector<vector<int>> res(1 << N, vector<int>());
    vector<vector<int>>::iterator iterSet = res.begin() + 1;
    for (int& n : nums) {
      while (iSubset < nSubset * 2) {
        (*iterSet).insert((*iterSet).end(), (*(iterSet - nSubset)).begin(),
                          (*(iterSet - nSubset)).end());
        (*iterSet).push_back(n);
        ++iterSet;
        ++iSubset;
      }
      nSubset *= 2;
    }

    return res;
  }

  vector<vector<int>> _subsets_BitManipulation(vector<int>& nums) {
    vector<vector<int>> res{{}};
    int N = nums.size(), numSets = 1 << N, iSet = 1;

    for (; iSet < numSets; ++iSet) {
      vector<int> subset;

      for (int iDigit = 0; iDigit < N; ++iDigit) {
        if (((iSet >> iDigit) & 1) == 1) {
          subset.push_back(nums[iDigit]);
        }
      }
      res.push_back(subset);
    }
    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {{1, 2, 3}, {0}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    vector<vector<int>> res = Solution().subsets(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
