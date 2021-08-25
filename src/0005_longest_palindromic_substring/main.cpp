#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Solution begin: Manacher's Algorithm
class Solution {
 public:
  Solution() {
    // Speedup
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }

  string longestPalindrome(string s) {
    int len = s.length();
    if (!len || len == 1) {
      return s;
    }
    // if s = "aba" => new_s = "%a%b%a%"
    int i_sym = 0, central = 0, right = 0, max_len = 0, max_idx = 0;
    // radius of longest palindrome centered at each position
    vector<int> FarWalk(2 * len + 1, 0);

    for (int i = 1; i < 2 * len - max_len; i++) {
      i_sym = 2 * central - i;

      // Check if current char is valid char, not `%`
      if (i % 2) FarWalk.at(i) = 1;

      if (right > i) {
        FarWalk.at(i) = min(FarWalk.at(i_sym), right - i);
      }

      while (s[(i - FarWalk.at(i)) / 2 - 1] == s[(i + FarWalk.at(i)) / 2] &&
             i > FarWalk.at(i)) {
        FarWalk.at(i) += 2;
      }

      if (FarWalk.at(i) + i > right) {
        right = FarWalk.at(i) + i;
        central = i;
        if (FarWalk.at(i) > max_len) {
          max_len = FarWalk.at(i);
          max_idx = i;
        }
      }
    }
    return s.substr((max_idx - max_len) / 2, max_len);
  }
};
// Solution end

// Solution2: dynamic programming
class Solution2 {
 public:
  Solution2() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }

  string longestPalindrome(string s) {
    size_t sLen = s.length();
    if (!sLen || sLen == 1) {
      return s;
    }

    // Create a matrix for dynamic programming
    // Array is much faster than std::vector, but cost more memory
    bool **isPal = new bool *[sLen];
    for (size_t i = 0; i < sLen; i++) {
      isPal[i] = new bool[i + 1];
    }

    size_t maxLen = 1, subBegin = 0;
    // check if s[i:j] is palindrome
    // e: end of substring, b: begin of substring
    for (size_t e = 0; e < sLen; e++) {
      isPal[e][e] = true;
      for (size_t b = 0; b < e; b++) {
        isPal[e][b] =
            (bool)(s[b] == s[e] && (e - b < 2 || isPal[e - 1][b + 1]));
        if (isPal[e][b] && maxLen < e - b + 1) {
          maxLen = e - b + 1;
          subBegin = b;
        }
      }
    }

    return s.substr(subBegin, maxLen);
  }
};
// Solution 2 end

int main() {
  vector<string> testStrs = {"babad", "cbbd", "a", "ac"};
  size_t numCase = testStrs.size();

  for (size_t i = 0; i < numCase; i++) {
    cout << "Example " << i + 1 << ":" << endl;
    cout << "Input: s = \"" << testStrs.at(i) << "\"" << endl;
    // string subStr = Solution().longestPalindrome(testStrs[i]);
    string subStr = Solution2().longestPalindrome(testStrs[i]);
    cout << "Output: \"" << subStr << "\"" << endl;
    cout << "========================" << endl;
  }
}
