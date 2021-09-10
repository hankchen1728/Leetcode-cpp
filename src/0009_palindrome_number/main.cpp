#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  bool isPalindrome(int x) {
    // units digit must be palindrome
    if (x >= 0 && x <= 9) return true;
    if (x < 0 || x % 10 == 0) return false;

    int y = 0;
    while (x > y) {
      y = 10 * y + (x % 10);
      if (y == x || y == (x /= 10)) return true;
    }
    return false;
  }
};
// Solution end

int main() {
  // Write something here
  vector<int> testCase = {121, -121, 10, -101};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "x = " << testCase[i] << endl;
    // Call the Solution function here!
    bool ans = Solution().isPalindrome(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << (ans ? "true" : "false") << endl;
    cout << "===========" << endl;
  }
}
