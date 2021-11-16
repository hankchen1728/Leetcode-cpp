#include <iostream>
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
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int nDays = temperatures.size();
    vector<int> res(nDays, 0);
    stack<int> histDays;

    for (int i = 0; i < nDays; i++) {
      while (!histDays.empty()) {
        if (temperatures[i] > temperatures[histDays.top()]) {
          res[histDays.top()] = i - histDays.top();
          histDays.pop();
        } else break;
      }
      histDays.push(i);
    }
    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testCase = {
      {73, 74, 75, 71, 69, 72, 76, 73}, {30, 40, 50, 60}, {30, 60, 90}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m temperatures = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    vector<int> res = Solution().dailyTemperatures(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
