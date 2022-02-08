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
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, size_t> cnt;

    for (int& val1 : nums1) {
      for (int& val2 : nums2) {
        // int sum = val1 + val2;
        // cnt[sum] = (cnt.find(sum) == cnt.end()) ? 1 : cnt[sum] + 1;
        cnt[val1 + val2]++;
      }
    }

    int res = 0;
    for (int& val3 : nums3) {
      for (int& val4 : nums4) {
        // int resid = -(val3 + val4);
        // if (cnt.find(resid) != cnt.end()) res += cnt[resid];
        res += cnt[-(val3+val4)];
      }
    }

    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<vector<int>>> testCase = {{{1, 2}, {-2, -1}, {-1, 2}, {0, 2}},
                                          {{0}, {0}, {0}, {0}}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums1 = " << intVectorToString(testCase[i][0])
         << ", nums2 = " << intVectorToString(testCase[i][1])
         << ", nums3 = " << intVectorToString(testCase[i][2])
         << ", nums4 = " << intVectorToString(testCase[i][3]) << endl;
    // Call the Solution function here!
    int res = Solution().fourSumCount(testCase[i][0], testCase[i][1],
                                      testCase[i][2], testCase[i][3]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
