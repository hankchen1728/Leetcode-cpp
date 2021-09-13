#include <iostream>
#include <string>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  string reverseWords(string s) {
    size_t r, len = s.length();
    for (size_t l = 0; l < len; l++) {
      if (s[l] != ' ') {
        r = l;
        // find next space char
        while (r < len && s[r] != ' ') r++;

        reverse(s.begin() + l, s.begin() + r);
        l = r;
      }
    }
    return s;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testCase = {"Let's take LeetCode contest", "God Ding"};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "s = \"" << testCase[i] << "\"" << endl;
    // Call the Solution function here!
    string s = Solution().reverseWords(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m \"" << s << "\"" << endl;
    cout << "===========" << endl;
  }
}
