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
  double average(vector<int>& salary) {
    // warning: please make sure the sum does NOT overflow
    int maxS = 1000, minS = 1e6, sumS = 0;
    for (int& n : salary) {
      maxS = max(n, maxS);
      minS = min(n, minS);
      sumS += n;
    }
    return (double)(sumS - minS - maxS) / (salary.size() - 2);
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {
      {4000, 3000, 1000, 2000},  // 2500.00000
      {1000, 2000, 3000},        // 2000.00000
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m salary = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    double res = Solution().average(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << std::fixed << std::setprecision(5) << res << endl;
    cout << "===========" << endl;
  }
}
