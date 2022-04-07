#include <iostream>
#include <queue>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  // Solution() {
  //   // Speed up
  //   ios::sync_with_stdio(false);
  //   cin.tie(nullptr);
  //   cout.tie(nullptr);
  // }
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(), stones.end());
    // for (const int& n : stones) pq.push(n);

    int w1, w2;

    while (pq.size() > 1) {
      w1 = pq.top();
      pq.pop();
      w2 = pq.top();
      pq.pop();

      if (w1 != w2) pq.push(w1 - w2);
    }

    return pq.empty() ? 0 : pq.top();
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {
      {2, 7, 4, 1, 8, 1},  // 1
      {1},                 // 1
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m stones = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().lastStoneWeight(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
