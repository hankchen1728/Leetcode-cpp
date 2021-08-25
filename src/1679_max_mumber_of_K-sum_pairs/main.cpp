#include <algorithm>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  Solution() {
    // Speedup
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#define endl "\n"
  }
  int maxOperations(vector<int>& nums, int k) {
    int cnt = 0;
    sort(nums.begin(), nums.end());
    size_t lPtr(0), rPtr(nums.size() - 1);

    while (lPtr < rPtr) {
      if (nums[lPtr] + nums[rPtr] == k) {
        cnt++;
        lPtr++;
        rPtr--;
      } else if (nums[lPtr] + nums[rPtr] < k) {
        lPtr++;
      } else {
        rPtr--;
      }
    }
    return cnt;
  }
};
// Solution end

int main() {
  vector<vector<int>> testNums = {{1, 2, 3, 4}, {3, 1, 3, 4, 3}};
  vector<int> testTarget = {5, 6};
  size_t numCase = 2;

  for (size_t i = 0; i < numCase; i++) {
    cout << "Example " << i+1 << ":" << endl;
    cout << "Input: nums = " << intVectorToString(testNums[i])
         << ", k = " << testTarget[i] << endl;
    int ans = Solution().maxOperations(testNums[i], testTarget[i]);
    cout << "Output:" << ans << endl;
    cout << "========================" << endl;
  }
}
