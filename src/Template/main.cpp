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
  void problem() {
    // The algorithm
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<int> testCase = {0, 1, 3};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m " << endl;
    // Call the Solution function here!
    Solution().problem();
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << endl;
    cout << "===========" << endl;
  }
}
