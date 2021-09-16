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
  int maxProfit(vector<int>& prices) {
    int profit = 0, minPrice = prices[0];

    for (size_t i = 1; i < prices.size(); i++) {
      if (prices[i] < minPrice) {
        minPrice = prices[i];
      } else {
        profit = max(profit, prices[i] - minPrice);
      }
    }
    return profit;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testCase = {{7,1,5,3,6,4},{7,6,4,3,1}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m " << "prices = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int ans = Solution().maxProfit(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
