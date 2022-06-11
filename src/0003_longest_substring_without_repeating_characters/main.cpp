#include <iostream>
#include <string>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution
{
 public:
  int lengthOfLongestSubstring(string s)
  {
    int16_t N = s.size();

    // array for recording position
    int16_t charPos[127];
    memset(charPos, -1, 127 * sizeof(int16_t));

    int maxLen = 0;

    char c;
    for (int16_t R = 0, L = -1; R < N; ++R)
    {
      c = s[R];
      // moving left position forward right or not
      L = max(charPos[c], L);

      // recording the position
      charPos[c] = R;
      // check if longest
      maxLen = max(maxLen, R - L);
    }

    return maxLen;
  }
};
// Solution end

int main()
{
  vector<string> testStrs{
      "abcabcbb",  // 3
      "bbbbb",     // 1
      "pwwkew",    // 3
  };

  for (size_t i_test = 0; i_test < testStrs.size(); i_test++)
  {
    cout << Bold("Example " + to_string(i_test + 1) + ":") << endl;
    // print the test case input here!
    cout << Bold("Input: ") << " s = " << testStrs[i_test] << endl;

    // Call the Solution function here!
    int lenSub = Solution().lengthOfLongestSubstring(testStrs[i_test]);
    cout << Bold("Output: ") << lenSub << endl;

    cout << "========================" << endl;
  }
}
