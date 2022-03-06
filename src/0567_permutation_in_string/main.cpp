#include <iostream>
#include <string>
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
  // Method 1
  bool checkInclusion(string s1, string s2) {
    // return _checkInclusion_freq(s1, s2);
    return _checkInclusion_two_pointers(s1, s2);
  }

  // method using two frequency table
  bool _checkInclusion_freq(string& s1, string& s2) {
    size_t len1 = s1.length(), len2 = s2.length();
    if (len1 > len2) return false;

    // table for recording character frequency
    // size of table is 26, since the string only contain lowercase
    vector<int16_t> freq1(26, 0), freq2(26, 0);
    for (size_t i = 0; i < len1; i++) {
      freq1[s1[i] - 'a']++;
      freq2[s2[i] - 'a']++;
    }

    if (freq1 == freq2) return true;
    for (size_t i = len1; i < len2; i++) {
      freq2[s2[i - len1] - 'a']--;
      freq2[s2[i] - 'a']++;

      if (freq1 == freq2) return true;
    }
    return false;
  }

  // method using two pointers
  bool _checkInclusion_two_pointers(string& s1, string& s2) {
    if (s1.size() > s2.size()) return false;

    int len1 = s1.size(), len2 = s2.size(), cnt = len1, L = 0, R = 0;
    vector<short> mp(123, 0);
    for (char& ch : s1) ++mp[ch];

    while (R < len2) {
      // current right char is in s1
      if (mp[s2[R++]]-- > 0) {
        cnt--;
        if (cnt == 0) return true;
      }
      // current sliding window has same length to s1
      if (R - L == len1) {
        if (mp[s2[L++]]++ >= 0) cnt++;
      }
    }
    return false;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testS1s = {"ab", "ab"};
  vector<string> testS2s = {"eidbaooo", "eidboaoo"};
  size_t nTest = testS1s.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "s1 = \"" << testS1s[i] << "\", s2 = \"" << testS2s[i] << "\""
         << endl;
    // Call the Solution function here!
    bool ans = Solution().checkInclusion(testS1s[i], testS2s[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << (ans ? "true" : "false") << endl;
    cout << "===========" << endl;
  }
}
