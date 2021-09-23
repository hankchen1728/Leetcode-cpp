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
  int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n > 0) {
      // if (n % 2) cnt++; n /= 2;
      cnt += (n & 1);
      n = n >> 1;
    }
    return cnt;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testN = {"00000000000000000000000000001011",
                          "00000000000000000000000010000000",
                          "11111111111111111111111111111101"};
  size_t nTest = testN.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "n = " << testN[i] << endl;
    // Call the Solution function here!
    uint32_t n = (uint32_t)stoul(testN[i], nullptr, 2);
    int res = Solution().hammingWeight(n);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
