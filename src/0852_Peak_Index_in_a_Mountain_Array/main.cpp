#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  // Solution() {
  //   // Speed up
  //   ios::sync_with_stdio(false);
  //   cin.tie(nullptr);
  //   cout.tie(nullptr);
  // }
  int peakIndexInMountainArray(vector<int>& arr) {
    int L = 0, R = arr.size() - 1, mid;

    while (L < R) {
      mid = (L + R) / 2;
      if (arr[mid] < arr[mid + 1]) {
        // decreasing part
        L = mid + 1;
      } else {
        // increasing part
        R = mid;
      }
    }

    return (int)L;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {
      {0, 1, 0},      // 1
      {0, 2, 1, 0},   // 1
      {0, 10, 5, 2},  // 1
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m arr = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().peakIndexInMountainArray(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
