#include <iostream>
#include <string>
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
  int numberOfUniqueGoodSubsequences(string binary) {
    const int MOD = 1e9 + 7;
    int dp[2] = {0, 0};

    for (const char& c : binary) {
      dp[c - '0'] = (dp[0] + dp[1] + c - '0') % MOD;
    }
    // Add the substring "0" back
    return (dp[0] + dp[1] + (binary.find('0') != string::npos)) % MOD;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testStrs = {"001", "11", "101"};
  size_t nTest = testStrs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "binary = \"" << testStrs[i] << "\"" << endl;
    // Call the Solution function here!
    int res = Solution().numberOfUniqueGoodSubsequences(testStrs[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
