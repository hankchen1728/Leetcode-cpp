#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  void problem() {
    // The algorithm
  }
};
// Solution end


int main() {
  // Write something here
  vector<int> testCase = {0, 1, 3};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m" << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:" << "\e[0m " << endl;
    // Call the Solution function here!
    Solution().problem();
    cout << "\e[1m" << "Output: " << endl;
    cout << "===========" << endl;
  }
}
