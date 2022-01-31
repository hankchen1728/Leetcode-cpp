#include <algorithm>
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
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    // sort the array
    sort(arr.begin(), arr.end());

    vector<vector<int>> res;
    int N = arr.size(), minDiff = INT_MAX, diff;
    for (int i = 0; i < N - 1; i++) {
      diff = arr[i + 1] - arr[i];
      if (diff < minDiff) {
        res.clear();
        minDiff = diff;
        res.push_back({arr[i], arr[i + 1]});
      } else if (diff == minDiff) {
        res.push_back({arr[i], arr[i + 1]});
      }
    }
    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {
      {4, 2, 1, 3}, {1, 3, 6, 10, 15}, {3, 8, -10, 23, 19, -4, -14, 27}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m arr = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    vector<vector<int>> res = Solution().minimumAbsDifference(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
