#include <cstring>
#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  const int MOD = 1e9 + 7;
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  int distinctSubseqII(string s) {
    int sLen = s.length();
    vector<int> letters(26, -1);   // position of each letter last appearence
    vector<int> res(sLen + 1, 0);  // res[i] means result of substr s[0:i]
    // const int MOD = 1e9 + 7;

    for (size_t i = 0; i < sLen; i++) {
      if (letters[s[i] - 'a'] < 0) {
        // current char not appeared yet
        // the increasing number are the `previous sum + 1`
        // (current letter is also a subseq)
        res[i + 1] = (int)((2 * (long)res[i] + 1) % this->MOD);
      } else {
        res[i + 1] = (int)((2 * (long)res[i] - (long)res[letters[s[i] - 'a']]) %
                           this->MOD);
      }
      // record the position of current letter
      letters[s[i] - 'a'] = i;
    }
    // correct to positive
    return (res[sLen] < 0) ? res[sLen] + this->MOD : res[sLen];
  }
  int distinctSubseqII_2(string s) {
    int res = 0, inc = 0, charIdx;
    int dp[26];
    memset(dp, 0, sizeof(dp[0]) * 26);

    for (const char& c : s) {
      charIdx = c - 'a';
      inc = (res - dp[charIdx] + 1) % this->MOD;
      res = (res + inc) % this->MOD;
      dp[charIdx] = (dp[charIdx] + inc) % this->MOD;
    }

    return (res + this->MOD) % this->MOD;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testStrs = {"abc", "aba", "aaa"};
  size_t nTest = testStrs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "s = \"" << testStrs[i] << "\"" << endl;
    // Call the Solution function here!
    int ans = Solution().distinctSubseqII_2(testStrs[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
