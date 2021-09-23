#include <_ctype.h>

#include <cctype>
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
  vector<string> letterCasePermutation(string s) {
    size_t sLen = s.size();
    vector<string> res = {""};

    for (char& c : s) {
      if (c - '0' <= 9) {
        for (string& substr : res) substr += c;
      } else {
        size_t numStr = res.size();
        for (size_t j = 0; j < numStr; j++) {
          res.push_back(res[j]);
          res[j] += tolower(c);
          res.back() += toupper(c);
        }
      }
    }
    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testStrs = {"a1b2", "3z4", "12345", "0"};
  size_t nTest = testStrs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "\"" << testStrs[i] << "\"" << endl;
    // Call the Solution function here!
    vector<string> res = Solution().letterCasePermutation(testStrs[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m [";
    for (string& s : res) cout << "\"" << s << "\",";
    cout << "]" << endl;
    cout << "===========" << endl;
  }
}
