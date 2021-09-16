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
  // Method 2
  bool _checkInclusion(string s1, string s2) {
    int16_t subLen = s1.length(), len = s2.length();
    // check length
    if (len < subLen) return false;

    vector<int16_t> mp(26, 0);
    // record the frequency of each char in s1
    for (char& c : s1) mp[c - 'a']++;

    // when every frequency in `mp` is 0, then the permutation is matched
    for (int16_t left = 0, right = 0; right < len; right++) {
      mp[s2[right] - 'a']--;
      if (mp[s2[right] - 'a'] < 0) {
        // limit left boundary (add frequency back)
        while (true) {
          mp[s2[left] - 'a']++;
          left++;
          if (mp[s2[left - 1] - 'a'] == 0) break;
        }
        cout << "Left = " << left << ", right = " << right << endl;
      } else if (right - left + 1 == subLen)
        return true;
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
