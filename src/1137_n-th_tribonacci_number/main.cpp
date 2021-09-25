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
  int tribonacci(int n) {
    // T0 = 0 and T1 = 1
    if (n < 2) return n;

    int temp, first = 0, second = 1, third = 1;

    for (int i = 0; i <= n - 3; i++) {
      temp = third;
      third = first + second + third;
      first = second;
      second = temp;
    }

    return third;
  }
};
// Solution end

int main() {
  // Write something here
  vector<int> testN = {4, 25, 0};
  size_t nTest = testN.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "n = " << testN[i] << endl;
    // Call the Solution function here!
    int res = Solution().tribonacci(testN[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
