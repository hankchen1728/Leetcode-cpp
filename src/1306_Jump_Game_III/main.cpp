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
  bool canReach(vector<int>& arr, int start) {
    if (start < 0 || start >= arr.size()) return false;

    int curr = arr[start];
    if (curr == 0) {
      return true;
    } else if (curr == -1) {
      return false;
    } else {
      // mark the attached position
      arr[start] = -1;
    }
    return canReach(arr, start + curr) || canReach(arr, start - curr);
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<vector<int>, int>> testCasePairs = {{{4, 2, 3, 0, 3, 1, 2}, 5},
                                                  {{4, 2, 3, 0, 3, 1, 2}, 0},
                                                  {{3, 0, 2, 1, 2}, 2}};
  size_t nTest = testCasePairs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m arr = " << intVectorToString(testCasePairs[i].first)
         << ", start = " << testCasePairs[i].second << endl;
    // Call the Solution function here!
    bool res =
        Solution().canReach(testCasePairs[i].first, testCasePairs[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << (res ? "true" : "false") << endl;
    cout << "===========" << endl;
  }
}
