#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  vector<int> nums;
  vector<vector<int>> res;
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  vector<vector<int>> permute(vector<int>& nums) {
    this->nums = nums;
    this->res.clear();
    vector<int> currPerm;
    vector<bool> visited(nums.size(), false);

    permDFS(visited, currPerm);
    return res;
  }

  void permDFS(vector<bool>& visited, vector<int>& currPerm) {
    if (currPerm.size() == this->nums.size()) {
      this->res.push_back(currPerm);
      return;
    }

    for (size_t i = 0; i < this->nums.size(); i++) {
      if (!visited[i]) {
        currPerm.push_back(nums[i]);
        visited[i] = true;
        permDFS(visited, currPerm);
        currPerm.pop_back();
        visited[i] = false;
      }
    }
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {{1, 2, 3}, {0, 1}, {1}, {0, 1, 2, 3, 4}};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << " nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    vector<vector<int>> res = Solution().permute(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
