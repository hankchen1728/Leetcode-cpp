#include <iostream>
#include <sstream>
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

  void getNextRevision(stringstream& ss, int& rev) {
    string revStr;
    rev = getline(ss, revStr, '.') ? stoi(revStr) : 0;
    return;
  }

  int compareVersion(string version1, string version2) {
    stringstream ss1(version1), ss2(version2);
    int res = 0, rev1, rev2;

    while (ss1 || ss2) {
      getNextRevision(ss1, rev1);
      getNextRevision(ss2, rev2);
      if (rev1 > rev2) {
        res = 1;
        break;
      } else if (rev1 < rev2) {
        res = -1;
        break;
      }
    }

    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<string, string>> testCase = {
      {"1.01", "1.001"}, {"1.0", "1.0.0"}, {"0.1", "1.1"}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input: \e[0m"
         << "version1 = " << std::quoted(testCase[i].first)
         << ", version2 = " << std::quoted(testCase[i].second) << endl;
    // Call the Solution function here!
    int res = Solution().compareVersion(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
