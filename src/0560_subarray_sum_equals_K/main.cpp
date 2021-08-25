#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int cnt = 0, contiSum = 0;
    size_t nLen = nums.size();
    unordered_map<int, int> sumFreq{{0, 1}};

    for (size_t i = 0; i < nLen; ++i) {
      contiSum += nums[i];
      if (sumFreq.find(contiSum - k) != sumFreq.end()) {
        cnt += sumFreq[contiSum - k];
      }
      sumFreq[contiSum]++;
    }
    return cnt;
  }
};
// Solution end

int main() {
  vector<vector<int>> testNums = {{1, 1, 1}, {1, 2, 3}};
  vector<int> testK = {2, 3};
  size_t numCases = 2;
  int ans;

  for (size_t i_case = 0; i_case < numCases; i_case++) {
    cout << "Example " << i_case << endl;
    ans = Solution().subarraySum(testNums[i_case], testK[i_case]);
    cout << "Input: nums = " << intVectorToString(testNums[i_case])
         << ", K = " << testK[i_case] << endl;
    cout << "Output: " << ans << endl;
    cout << "========================" << endl;
  }
}
