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
  int maxPower(string s) {
    int res = 0, sLen = s.length();

    for (int i = 0; i < sLen;) {
        char c = s[i];
        int j = i+1;
        // search until end or different character
        while (j < sLen && c == s[j]) j++;

        // update result
        if (j - i > res) res = j - i;
        i = j;
    }
    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<string> testCase = {"leetcode", "abbcccddddeeeeedcba",
                             "triplepillooooow"};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m s = " << testCase[i] << endl;
    // Call the Solution function here!
    int res = Solution().maxPower(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
