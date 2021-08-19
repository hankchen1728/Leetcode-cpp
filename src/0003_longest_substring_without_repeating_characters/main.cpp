#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Solution begin
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    // Check if empty string
    size_t sLen = s.size();
    if (sLen == 0) return 0;

    // vector for recording position
    vector<int> charPos(128, -1);
    int maxLen = 0;  // length of current extract substring
    int rem = -1;    // left position of current extract substring

    char c;
    for (int i = 0; i < sLen; i++) {
      c = s[i];
      // moving left position forward right or not
      rem = max(charPos[c], rem);

      // recording the position
      charPos[c] = i;
      // check if longest
      maxLen = max(maxLen, i - rem);
    }

    return maxLen;
  }
};
// Solution end

int main() {
  vector<string> testStrs{"abcabcbb", "bbbbb", "pwwkew"};

  for (size_t i_test = 0; i_test < testStrs.size(); i_test++) {
    int lenSub = Solution().lengthOfLongestSubstring(testStrs[i_test]);
    cout << "Example " << i_test+1 << endl;
    cout << "Input: s = " << testStrs[i_test] << endl;
    cout << "Output:" << lenSub << endl;
    cout << "========================" << endl;
  }
}
