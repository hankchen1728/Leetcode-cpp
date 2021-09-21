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
  int climbStairs(int n) {
    vector<int> nClimb(n + 1, 1);

    for (size_t i = 1; i < n; i++) {
      nClimb[i + 1] = nClimb[i - 1] + nClimb[i];
    }

    return nClimb[n];
  }
};
// Solution end

int main() {
  // Write something here
  vector<int> testN = {2, 3};
  size_t nTest = testN.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "n = " << testN[i] << endl;
    // Call the Solution function here!
    int res = Solution().climbStairs(testN[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
