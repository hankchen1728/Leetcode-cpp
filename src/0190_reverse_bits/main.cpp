#include <_types/_uint32_t.h>

#include <bitset>
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
  uint32_t reverseBits(uint32_t n) {
    // The algorithm
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
      res = res << 1;
      res += (n & 1);
      n = n >> 1;
    }
    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testN = {"00000010100101000001111010011100",
                          "11111111111111111111111111111101"};
  size_t nTest = testN.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "n = " << testN[i] << endl;
    uint32_t n = (uint32_t)stoul(testN[i], nullptr, 2);
    // Call the Solution function here!
    uint32_t res = Solution().reverseBits(n);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
