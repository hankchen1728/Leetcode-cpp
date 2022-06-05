#include <iostream>
#include <unordered_map>
#include <vector>

#include "myUtils.h"

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
  int countTriplets(vector<int>& arr) {
    unordered_map<int, int> xor2cnt{{0, 1}}, xor2idxSum{{0, -1}};

    int preXOR = 0;
    int cnt = 0;
    int N = arr.size();

    for (int k = 0; k < N; ++k) {
      preXOR ^= arr[k];

      // calculate the count
      cnt += xor2cnt[preXOR]++ * (k - 1) - xor2idxSum[preXOR];

      // add the current index to sum: i_1 + ... + i_n
      xor2idxSum[preXOR] += k;
    }

    return cnt;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {
      {2, 3, 1, 6, 7},
      {1, 1, 1, 1, 1},
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m arr = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().countTriplets(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
