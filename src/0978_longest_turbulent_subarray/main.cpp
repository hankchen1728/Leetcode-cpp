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
  int maxTurbulenceSize(vector<int>& arr) {
    int arrLen = arr.size(), nDec = 1, nInc = 1, maxLen = 1;

    for (int i = 1; i < arrLen; i++) {
      if (arr[i] > arr[i - 1]) {
        nInc = nDec + 1;
        nDec = 1;
        maxLen = max(maxLen, nInc);
      } else if (arr[i] < arr[i - 1]) {
        nDec = nInc + 1;
        nInc = 1;
        maxLen = max(maxLen, nDec);
      } else {
        nDec = 1;
        nInc = 1;
      }
    }
    return maxLen;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testArrs = {{9, 4, 2, 10, 7, 8, 8, 1, 9},
                                  {4, 8, 12, 16},
                                  {100},
                                  {0, 1, 1, 0, 1, 0, 1, 1, 0, 0}};
  size_t nTest = testArrs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "arr = " << intVectorToString(testArrs[i]) << endl;
    // Call the Solution function here!
    int ans = Solution().maxTurbulenceSize(testArrs[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
