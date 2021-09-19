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
  int numDistinct(string s, string t) {
    size_t lenS = s.length(), lenT = t.length();
    int dp[lenT + 1][lenS + 1];

    // any string has only one subseq "" match the emtpy pattern ""
    for (size_t j = 0; j <= lenS; j++) dp[0][j] = 1;
    // empty subseq does not match any non-empty pattern
    for (size_t i = 1; i <= lenT; i++) dp[i][0] = 0;

    for (size_t i = 1; i <= lenT; i++) {
      for (size_t j = 1; j <= lenS; j++) {
        if (s[j - 1] == t[i - 1]) {
          // dp[i][j] = dp[i][j-1] + dp[i-1][j-1]
          // prevent overflow
          dp[i][j] = (int)(((long)dp[i][j - 1] + (long)dp[i - 1][j - 1]) %
                           (long)2147483648);
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    return dp[lenT][lenS];
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testS = {"rabbbit", "babgbag"};
  vector<string> testT = {"rabbit", "bag"};
  size_t nTest = testS.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "s = " << testS[i] << ", t = " << testT[i] << endl;
    // Call the Solution function here!
    int ans = Solution().numDistinct(testS[i], testT[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
