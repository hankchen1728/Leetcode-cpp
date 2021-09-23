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
  bool isPowerOfTwo(int n) {
    while (n > 1) {
      // more than 1 bit in the binary string
      if (n & 1) return false;
      n = n >> 1;
    }
    return (n == 1) ? true : false;
  }
};
// Solution end

int main() {
  // Write something here
  vector<int> testN = {1, 16, 3, 4, 5};
  size_t nTest = testN.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "n = " << testN[i] << endl;
    // Call the Solution function here!
    bool res = Solution().isPowerOfTwo(testN[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << (res ? "true" : "false") << endl;
    cout << "===========" << endl;
  }
}
