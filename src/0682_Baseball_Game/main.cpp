#include <iostream>
#include <stack>
#include <vector>

#include "myUtils.h"

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
  int calPoints(vector<string>& ops) {
    stack<int> st;
    int res = 0;
    int prev_v, new_v;

    for (const string& op : ops) {
      switch (op[0]) {
        case '+': {
          prev_v = st.top(), new_v = prev_v;
          st.pop();
          // add two previous score
          new_v += st.top();
          // add to final sum
          res += new_v;
          st.push(prev_v);
          st.push(new_v);
          break;
        }
        case 'D': {
          new_v = st.top() * 2;
          st.push(new_v);
          res += new_v;
          break;
        }
        case 'C': {
          res -= st.top();
          st.pop();
          break;
        }
        default: {
          new_v = stoi(op);
          st.push(new_v);
          res += new_v;
          break;
        }
      }
    }
    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<string>> testCase = {
      {"5", "2", "C", "D", "+"},                  // 30
      {"5", "-2", "4", "C", "D", "9", "+", "+"},  // 27
      {"1"},                                      // 1
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m " << endl;
    // Call the Solution function here!
    int res = Solution().calPoints(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
