#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution {
  size_t skip = 1;

 public:
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  bool validPalindrome(string s) { return subPalindrome(s, 0, s.length() - 1); }

  bool subPalindrome(string &s, size_t L, size_t R) {
    while (L < R) {
      if (s[L] != s[R]) {
        if (skip > 0) {
          skip = 0;
          return subPalindrome(s, L + 1, R) || subPalindrome(s, L, R - 1);
        } else {
          return false;
        }
      }
      ++L;
      --R;
    }
    return true;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<string> testCase = {
      "aba",   // true
      "abca",  // true
      "abc",   // false
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m " << quoted(testCase[i]) << endl;
    // Call the Solution function here!
    bool res = Solution().validPalindrome(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << BOOL2STR(res) << endl;
    cout << "===========" << endl;
  }
}
