#include <iostream>
#include <sstream>
#include <stack>
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
  string simplifyPath(string path) {
    stack<string> st;

    stringstream ss(path);
    string dirname;
    while (std::getline(ss, dirname, '/')) {
      if (dirname == "..") {
        if (!st.empty()) st.pop();
      } else if (!dirname.empty() && dirname != ".") {
        st.push(dirname);
      }
    }

    string res;
    while (!st.empty()) {
      dirname = st.top();
      st.pop();
      res.insert(0, "/" + dirname);
    }

    return res.empty() ? "/" : res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<string> testCase = {
      "/home/",       // "/home"
      "/../",         // "/"
      "/home//foo/",  // "/home/foo"
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m path = " << quoted(testCase[i]) << endl;
    // Call the Solution function here!
    string res = Solution().simplifyPath(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << quoted(res) << endl;
    cout << "===========" << endl;
  }
}
