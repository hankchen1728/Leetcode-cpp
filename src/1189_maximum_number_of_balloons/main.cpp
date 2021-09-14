#include <sys/_types/_int16_t.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
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
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> mp = {
        {'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};

    for (char& ch : text) {
      switch (ch) {
        case 'b':
        case 'a':
        case 'l':
        case 'o':
        case 'n':
          mp[ch]++;
          break;
      }
    }

    int maxNum = INT_MAX;
    string chs("balon");
    for (char& c : chs) {
      if (c == 'l' || c == 'o') {
        maxNum = min(maxNum, mp[c] / 2);
      } else {
        maxNum = min(maxNum, mp[c]);
      }
    }
    return maxNum;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testStrs = {"nlaebolko", "loonbalxballpoon", "leetcode",
                             "balon"};
  size_t nTest = testStrs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "text = \"" << testStrs[i] << "\"" << endl;
    // Call the Solution function here!
    int ans = Solution().maxNumberOfBalloons(testStrs[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
