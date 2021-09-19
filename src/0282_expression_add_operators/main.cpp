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
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    dfs(num, target, 0, 0, "", res);
    return res;
  }

  /**
   * Running deepth-first search to find all valid expression
   *
   * @param num: remained digits
   * @param target: target of expected expression
   * @param diff: effect of last operand in the expression `curExp`
   * @param curSum: calculation result of the expression `curExp`
   * @param curExp: expression
   * @param res: all expressions matching the `target`
   */
  void dfs(string& num, int& target, long diff, long curSum, string curExp,
           vector<string>& res) {
    if (num.empty() && curSum == (long)target) {
      res.push_back(curExp);
    }

    long curNum;
    string curNumStr, Digits;
    for (size_t i = 1; i <= num.size(); i++) {
      curNumStr = num.substr(0, i);
      if (curNumStr[0] == '0' && curNumStr.length() > 1) return;
      curNum = stol(curNumStr);

      Digits = num.substr(i);
      if (curExp.empty()) {
        dfs(Digits, target, curNum, curNum, curNumStr, res);
      } else {
        // plus
        dfs(Digits, target, curNum, curSum + curNum, curExp + "+" + curNumStr,
            res);
        // minus
        dfs(Digits, target, -curNum, curSum - curNum, curExp + "-" + curNumStr,
            res);
        // multiply
        dfs(Digits, target, diff * curNum, (curSum - diff) + (diff * curNum),
            curExp + "*" + curNumStr, res);
      }
    }
    return;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testNumstr = {"123", "232", "105", "00", "3456237490"};
  vector<int> testTargets = {6, 8, 5, 0, 9191};
  size_t nTest = testNumstr.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m " << endl;
    // Call the Solution function here!
    vector<string> res = Solution().addOperators(testNumstr[i], testTargets[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m "
         << "[";
    for (string& s : res) cout << "\"" << s << "\",";
    cout << "]" << endl;
    cout << "===========" << endl;
  }
}
