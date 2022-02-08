#include <iostream>
#include <utility>
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
  char findTheDifference(string s, string t) {
    char res = 0;
    for (char& c : s) res ^= c;
    for (char& c : t) res ^= c;
    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<string, string>> testCase = {{"abcd", "abcde"}, {"", "y"}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m s = \"" << testCase[i].first << "\", t = \""
         << testCase[i].second << "\"" << endl;
    // Call the Solution function here!
    char res =
        Solution().findTheDifference(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m \"" << res << "\"" << endl;
    cout << "===========" << endl;
  }
}
