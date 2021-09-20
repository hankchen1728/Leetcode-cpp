#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int n, k;
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  vector<vector<int>> combine(int n, int k) {
    this->n = n;
    this->k = k;
    vector<vector<int>> res;
    vector<int> initCmb;

    combDFS(res, initCmb, 1);
    return res;
  }

  void combDFS(vector<vector<int>>& res, vector<int>& currCmb, int currNum) {
    if (currCmb.size() == this->k) {
      res.push_back(currCmb);
      return;
    }

    for (int newNum = currNum; newNum <= this->n; newNum++) {
      // add a new number into current combination
      currCmb.push_back(newNum);
      combDFS(res, currCmb, newNum + 1);
      // remove the new added number
      currCmb.pop_back();
    }
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testPairs = {{4, 2}, {1, 1}, {5, 3}};
  size_t nTest = testPairs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "m = " << testPairs[i][0] << ", n = " << testPairs[i][1] << endl;
    // Call the Solution function here!
    vector<vector<int>> res =
        Solution().combine(testPairs[i][0], testPairs[i][1]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
