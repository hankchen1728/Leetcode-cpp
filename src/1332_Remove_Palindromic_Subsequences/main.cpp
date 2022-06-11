#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution
{
 public:
  // Solution()
  // {
  //   // Speed up
  //   ios::sync_with_stdio(false);
  //   cin.tie(nullptr);
  //   cout.tie(nullptr);
  // }

  int removePalindromeSub(string s)
  {
    int16_t L = 0, R = s.length() - 1;

    while (L < R)
    {
      if (s[L++] != s[R--]) return 2;
    }

    return 1;
  }
};
// Solution end

int main()
{
  cout << "\n===========" << endl;

  // Setting the test cases
  vector<string> testCase = {
      "ababa",  // 1
      "abb",    // 2
      "baabb",  // 2
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++)
  {
    cout << Bold("Example " + to_string(i + 1) + ":") << endl;
    // print the test case input here!
    cout << Bold("Input: ") << testCase[i] << endl;
    // Call the Solution function here!
    int res = Solution().removePalindromeSub(testCase[i]);
    cout << Bold("Output: ") << res << endl;
    cout << "===========" << endl;
  }
}
