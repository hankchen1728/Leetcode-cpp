#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int subtractProductAndSum(int n) {
    int dSum = 0, dProd = (n == 0 ? 0 : 1);

    while (n > 0) {
      dSum += n % 10;
      dProd *= n % 10;
      n /= 10;
    }
    return dProd - dSum;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<int> testCase = {
      234,   // 15
      4421,  // 21
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m n = " << testCase[i] << endl;
    // Call the Solution function here!
    int res = Solution().subtractProductAndSum(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
