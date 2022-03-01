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
  int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int& n : nums) mp[n]++;

    int res = 0;
    if (k > 0) {
      for (auto& it : mp) {
        if (mp.find(it.first + k) != mp.end()) res++;
      }
    } else {
      for (auto& it : mp) {
        if (it.second > 1) res++;
      }
    }
    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<vector<int>, int>> testCase = {
      {{3, 1, 4, 1, 5}, 2}, {{1, 2, 3, 4, 5}, 1}, {{1, 3, 1, 5, 4}, 0}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i].first)
         << ", k = " << testCase[i].second << endl;
    // Call the Solution function here!
    int res = Solution().findPairs(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
