#include <iostream>
#include <string>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int res = 0;
    for (char& c : columnTitle) {
      res = res * 26 + (c - 64);
    }
    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<string> testCase = {"A", "AB", "ZY"};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m columnTitle = \"" << testCase[i] << "\"" << endl;
    // Call the Solution function here!
    int res = Solution().titleToNumber(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
