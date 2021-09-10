#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int firstBad;
  Solution(int bad) : firstBad(bad) {
    // Speedup
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int firstBadVersion(int n) {
    int l = 1, r = n, c;
    while (l < r) {
      c = l + (r - l) / 2; // be ware of overflow
      if (isBadVersion(c)) {
        // c might be the first bad version
        // thus it's better to preserve c in the search scope
        r = c;
      } else {
        l = c + 1;
      }
    }
    return l;
  }
  // API isBadVersion
  bool isBadVersion(int version) {
    return (version >= firstBad) ? true : false;
  }
};
// Solution end

int main() {
  // Write something here
  vector<int> testN = {5, 1, 2147483647};
  vector<int> testBad = {4, 1, 2147483647};
  size_t nTest = testN.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "n = " << testN[i] << ", bad = " << testBad[i] << endl;
    // Call the Solution function here!
    int ans = Solution(testBad[i]).firstBadVersion(testN[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
