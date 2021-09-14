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
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // if nums2 is empty
    if (n == 0) return;

    // if nums1 is empty
    if (m == 0) {
      nums1 = nums2;
      return;
    }
    int16_t p1 = m - 1, p2 = n - 1, pos = nums1.size() - 1;

    while (p1 >= 0 && p2 >= 0) {
      if (nums1[p1] > nums2[p2]) {
        nums1[pos--] = nums1[p1--];
      } else {
        nums1[pos--] = nums2[p2--];
      }
    }

    while (p2 >= 0) {
      nums1[pos--] = nums2[p2--];
    }
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums1 = {{1, 2, 3, 0, 0, 0}, {1}, {0}};
  vector<vector<int>> testNums2 = {{2, 5, 6}, {}, {1}};
  vector<int> testM = {3, 1, 0};
  vector<int> testN = {3, 0, 1};
  size_t nTest = testNums1.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums1 = " << intVectorToString(testNums1[i])
         << ", m = " << testM[i]
         << ", nums2 = " << intVectorToString(testNums2[i])
         << ", n = " << testN[i] << endl;
    // Call the Solution function here!
    Solution().merge(testNums1[i], testM[i], testNums2[i], testN[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(testNums1[i]) << endl;
    cout << "===========" << endl;
  }
}
