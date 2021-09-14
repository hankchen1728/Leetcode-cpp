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
  bool isLetter(char& c) {
      if (c < 65 || (c > 90 && c < 97))
          return false;
      return true;
  }
  string reverseOnlyLetters(string s) {
    size_t len = s.size(), l = 0, r = len - 1;
    char temp;
    while (true) {
      while (l < r && !isLetter(s[l])) l++;
      while (r > l && !isLetter(s[r])) r--;
      if (l < r) {
        temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++; r--;
      } else
        break;
    }
    return s;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testStrs = {"ab-cd", "a-bC-dEf-ghIj", "Test1ng-Leet=code-Q!"};
  size_t nTest = testStrs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "s = \"" << testStrs[i] << "\"" << endl;
    // Call the Solution function here!
    string s = Solution().reverseOnlyLetters(testStrs[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m \"" << s << "\"" << endl;
    cout << "===========" << endl;
  }
}
