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
  string breakPalindrome(string palindrome) {
    size_t sLen = palindrome.length();
    if (sLen == 1) return "";

    // only need to check first half of the string
    // e.g. if the length of string is old
    // no need to check the central character
    for (size_t i = 0; i < sLen / 2; i++) {
      if (palindrome[i] > 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }
    }
    palindrome[sLen - 1] = 'b';
    return palindrome;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testStrs = {"abccba", "a", "aa", "aba"};
  size_t nTest = testStrs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "\"" << testStrs[i] << "\"" << endl;
    // Call the Solution function here!
    string res = Solution().breakPalindrome(testStrs[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m "
         << "\"" << res << "\"" << endl;
    cout << "===========" << endl;
  }
}
