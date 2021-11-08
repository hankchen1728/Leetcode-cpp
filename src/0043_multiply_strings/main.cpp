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
  string multiply(string num1, string num2) {
    int l1 = num1.size(), l2 = num2.size();
    // vector<int> mulDigits(l1 + l2, 0);
    int mulDigits[l1 + l2];
    memset(mulDigits, 0, sizeof(mulDigits));

    int pos;
    for (int pos1 = l1 - 1; pos1 >= 0; pos1--) {
      for (int pos2 = l2 - 1; pos2 >= 0; pos2--) {
        // find the position to update
        pos = pos1 + pos2;
        // consider the digit already exist
        mulDigits[pos + 1] += (num1[pos1] - '0') * (num2[pos2] - '0');
        mulDigits[pos] += mulDigits[pos + 1] / 10;
        mulDigits[pos + 1] %= 10;
      }
    }

    string res = "";
    for (int& digit : mulDigits) {
      // avoid leading zeros
      if (!res.empty() || digit > 0) {
        res.push_back(digit + '0');
      }
    }
    res = res.empty() ? "0" : res;

    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<pair<string, string>> testStrPairs = {{"2", "3"}, {"123", "456"}};
  size_t nTest = testStrPairs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m num1 = \"" << testStrPairs[i].first << "\", num2 = \""
         << testStrPairs[i].second << "\"" << endl;
    // Call the Solution function here!
    string res =
        Solution().multiply(testStrPairs[i].first, testStrPairs[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m \"" << res << "\"" << endl;
    cout << "===========" << endl;
  }
}
