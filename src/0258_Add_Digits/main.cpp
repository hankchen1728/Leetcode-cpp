#include <iostream>
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
  int addDigits(int num) {
    int res = num % 9;
    return (num > 0 && res == 0) ? 9 : res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<int> testCase = {38, 0};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m num = " << testCase[i] << endl;
    // Call the Solution function here!
    int res = Solution().addDigits(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
