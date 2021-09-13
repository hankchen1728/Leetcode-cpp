#include <iostream>
#include <string>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  void reverseString(vector<char>& s) {
    char temp;
    // only need to operate ( (length) / 2 ) swap
    for (size_t i = 0, len = s.size(); i < len / 2; i++) {
      temp = s[i];
      s[i] = s[len - i - 1];
      s[len - i - 1] = temp;
    }
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<char>> testStrs = {
      {'A'}, {'h', 'e', 'l', 'l', 'o'}, {'H', 'a', 'n', 'n', 'a', 'h'}};
  size_t nTest = testStrs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "s = " << charVectorToString(testStrs[i]) << endl;
    // Call the Solution function here!
    Solution().reverseString(testStrs[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << charVectorToString(testStrs[i]) << endl;
    cout << "===========" << endl;
  }
}
