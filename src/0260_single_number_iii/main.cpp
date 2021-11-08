#include <bitset>
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
  vector<int> singleNumber(vector<int>& nums) {
    // find the bits appear in odd times
    // use long long type to avoid overflow
    long long int odd = 0;
    for (int& n : nums) odd ^= n;

    // Get the smallest non-zero bit
    int Rbit = odd & -odd;
    // int bit = -1;
    // while (((odd >> ++bit) & 1) == 0) { }

    int res0 = 0;
    // compute the XOR again but skipping those numbers contain the above bit
    for (int& n : nums) {
      res0 ^= (n & Rbit) != 0 ? n : 0;
      // res[0] ^= (n >> bit & 1) ? n : 0;
    }
    vector<int> res{res0, (int)(res0 ^ odd)};

    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {{1, 2, 1, 3, 2, 5}, {-1, 0}, {0, 1}};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    vector<int> res = Solution().singleNumber(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
