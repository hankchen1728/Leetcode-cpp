#include <iostream>
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
  vector<int> findAnagrams(string s, string p) {
    // create hash table of p
    int sSize = s.size(), pSize = p.size();
    if (pSize > sSize) return {};

    vector<int> pTable(26, 0), res;
    for (char& c : p) pTable[c - 'a']++;

    int i = 0;
    for (; i < pSize - 1; i++) {
      pTable[s[i] - 'a']--;
    }
    for (; i < sSize; i++) {
      pTable[s[i] - 'a']--;
      if (all_of(pTable.begin(), pTable.end(), [](int v) { return v == 0; })) {
        res.push_back(i + 1 - pSize);
      }
      pTable[s[i + 1 - pSize] - 'a']++;
    }

    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<string, string>> testCase = {{"cbaebabacd", "abc"},
                                           {"abab", "ab"}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m s = \"" << testCase[i].first << "\", p = \""
         << testCase[i].second << "\"" << endl;
    // Call the Solution function here!
    vector<int> res =
        Solution().findAnagrams(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
