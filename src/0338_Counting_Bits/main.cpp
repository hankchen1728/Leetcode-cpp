#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> res(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      // "i >> 1" means remove the rightest bit
      res[i] = (i % 2) + res[(i >> 1)];
    }

    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<int> testCase = {2, 5};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m n = " << testCase[i] << endl;
    // Call the Solution function here!
    vector<int> res = Solution().countBits(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
