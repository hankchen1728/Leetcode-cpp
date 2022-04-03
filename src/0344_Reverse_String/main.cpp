#include <iostream>
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
  void reverseString(vector<char>& s) {
    size_t strLen = s.size();
    for (size_t i = 0; i < strLen / 2; ++i) {
      swap(s[i], s[strLen - i - 1]);
    }
    return;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<char>> testCase = {
      {'h', 'e', 'l', 'l', 'o'},       // ["o","l","l","e","h"]
      {'H', 'a', 'n', 'n', 'a', 'h'},  // ["h","a","n","n","a","H"]
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m " << charVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    vector<char> res(testCase[i]);
    Solution().reverseString(res);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << charVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
