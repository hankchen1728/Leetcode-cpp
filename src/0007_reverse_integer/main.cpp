#include <iostream>
#include <vector>

using namespace std;

// Solution begin
class Solution {
 public:
  int reverse(int x) {
    int ans = 0;
    while (x != 0) {
      // Check overflow
      if (ans > INT_MAX / 10 || ans < INT_MIN / 10) return 0;
      ans = 10 * ans + x % 10;
      x /= 10;
    }
    return ans;
  }
};
// Solution end

int main() {
  // Write something here
  vector<int> testCase = {123, -123, 0, -2147483412};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:\e[0m x = " << testCase[i] << endl;
    // Call the Solution function here!
    int ans = Solution().reverse(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m" << ans << endl;
    cout << "===========" << endl;
  }
}
