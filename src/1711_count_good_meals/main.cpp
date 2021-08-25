#include <iostream>
#include <unordered_map>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
#define ll long long
 public:
  int countPairs(vector<int> &nums) {
    // initial the list of power of 2, {1, 2, 4, 8 ...}
    vector<int> power2s(22, 1);
    for (size_t i = 1; i < power2s.size(); i++) {
      power2s[i] = power2s[i - 1] * 2;
    }

    // Count the frequency of each number
    unordered_map<int, int> numFreq;
    for (int &num : nums) {
      numFreq[num]++;
    }

    int mod = 1e9 + 7;
    // use long long int to avoid overflow
    ll int cnt = 0;      // count of those pairs consist of same number, such as (1,1)
    ll int diffCnt = 0;  // count of those pair consist of different numbers, such as (1,3)
    for (auto i = numFreq.begin(); i != numFreq.end(); i++) {
      for (int &pow2 : power2s) {
        if (i->first * 2 == pow2) {
          // twice of current number is power of 2
          if (i->second > 1) {
            cnt += (long long)i->second * (i->second - 1) / 2;
          }
        } else {
          if (numFreq.find(pow2 - i->first) != numFreq.end()) {
            diffCnt += (long long)i->second * numFreq[pow2 - i->first];
          }
        }
      }
    }

    return (int)((cnt + diffCnt / 2) % mod);
  }
};
// Solution end

int main() {
  vector<vector<int>> testNums = {{1, 3, 5, 7, 9}, {1, 1, 1, 3, 3, 3, 7}};
  size_t numCase = testNums.size();

  for (size_t i = 0; i < numCase; i++) {
    cout << "Example " << i + 1 << ":" << endl;
    cout << "Input: deliciousness = " << intVectorToString(testNums[i]) << endl;
    int ans = Solution().countPairs(testNums[i]);
    cout << "Output:" << ans << endl;
    cout << "========================" << endl;
  }
}
