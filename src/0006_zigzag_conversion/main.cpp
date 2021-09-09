#include <sys/_types/_size_t.h>

#include <iostream>
#include <string>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  Solution() {
    // Speedup
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string result = "";
    size_t len = s.length();
    // first row
    for (size_t i = 0; i < len; i += (2 * numRows - 2)) result += s[i];

    // second row and others
    for (size_t row = 1; row < numRows - 1; ++row) {
      bool vert = true;
      for (size_t pos = row; pos < len;) {
        result += s[pos];
        pos += vert ? 2 * (numRows - row - 1) : 2 * row;
        vert = !vert;
      }
    }

    // Last row
    for (size_t i = numRows - 1; i < len; i += (2 * numRows - 2))
      result += s[i];
    return result;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testStrs = {"PAYPALISHIRING", "PAYPALISHIRING", "A"};
  vector<int> testRows = {3, 4, 1};
  size_t nTest = testStrs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input: s = \"" << testStrs[i] << "\", numRows = " << testRows[i]
         << endl;
    // Call the Solution function here!
    string ans = Solution().convert(testStrs[i], testRows[i]);
    cout << "Output: \"" << ans << "\"" << endl;
    cout << "===========" << endl;
  }
}
