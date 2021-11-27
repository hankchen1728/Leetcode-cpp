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

  vector<int> productExceptSelf(vector<int>& nums) {
    int N = nums.size(), R = 1;
    vector<int> res(N, 1);

    for (int i = 1; i < N; i++) {
      res[i] = res[i - 1] * nums[i - 1];
    }

    for (int j = N - 2; j >= 0; j--) {
        R *= nums[j + 1];
        res[j] *= R;
    }

    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {{1, 2, 3, 4}, {-1, 1, 0, -3, 3}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    vector<int> res = Solution().productExceptSelf(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
