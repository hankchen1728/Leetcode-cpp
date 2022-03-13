#include <stack>
#include <unordered_map>
#include <vector>

#include "../Utils/myUtils.h"

// #define DEBUG

using namespace std;

// Solution begin
class Solution {
  unordered_map<char, char> Right2Left{
      {')', '('},
      {']', '['},
      {'}', '{'},
  };

 public:
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  bool isValid(string s) {
    stack<char> st;

    for (char& c : s) {
      if (Right2Left[c] > 0) {  // right bracket
        if (!st.empty() && st.top() == Right2Left[c]) {
          st.pop();
        } else {
          return false;
        }
      } else {
        st.push(c);
      }

#ifdef DEBUG
      cout << "Stack: ";
      PrintStack(st);
      cout << endl;
#endif  // DEBUG
    }

    return st.empty() ? true : false;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<string> testCase = {
      "()",      // true
      "()[]{}",  // true
      "(]",      // false
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m s = " << quoted(testCase[i]) << endl;
    // Call the Solution function here!
    bool res = Solution().isValid(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << BOOL2STR(res) << endl;
    cout << "===========" << endl;
  }
}
