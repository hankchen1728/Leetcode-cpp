#include <iostream>
#include <unordered_map>
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

  int majorityElement(vector<int>& nums) {
    // return _majorityElement_HashTable(nums);
    return _majorityElement_BoyerMoore_Voting(nums);
  }

  int _majorityElement_HashTable(vector<int>& nums) {
    unordered_map<int, size_t> mp;
    size_t maxCnt = 0, thres = nums.size() / 2, res;

    for (int& n : nums) {
      ++mp[n];
      if (mp[n] > maxCnt) {
        maxCnt = mp[n];
        res = n;
        if (maxCnt > thres) break;
      }
    }
    return res;
  }

  int _majorityElement_BoyerMoore_Voting(vector<int>& nums) {
    int candidate;
    uint16_t cnt = 0;

    for (int& n : nums) {
      if (cnt == 0) candidate = n;

      cnt += ((n == candidate) ? 1 : -1);
    }
    return candidate;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {{3, 2, 3}, {2, 2, 1, 1, 1, 2, 2}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().majorityElement(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
