#include <iostream>
#include <unordered_map>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> mp;
    for (int& n : nums) {
      if (mp.find(n) != mp.end()) {
        return true;
      } else {
        mp[n] = 1;
      }
    }
    return false;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testCase = {
      {1, 2, 3, 1}, {1, 2, 3, 4}, {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    bool ans = Solution().containsDuplicate(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << (ans ? "true" : "false") << endl;
    cout << "===========" << endl;
  }
}
