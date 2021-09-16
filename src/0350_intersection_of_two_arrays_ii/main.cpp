#include <algorithm>
#include <iostream>
#include <unordered_map>
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
  // Method 1
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // if (nums2.size() < nums1.size()) return intersect(nums2, nums1);

    unordered_map<int, int16_t> freq1;
    for (int& num : nums1) freq1[num]++;

    vector<int> res;
    for (int& num : nums2) {
      if (freq1[num] > 0) {
        freq1[num]--;
        res.push_back(num);
      }
    }
    return res;
  }
  // Method 2
  vector<int> _intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    size_t len1 = nums1.size(), len2 = nums2.size(), p1 = 0, p2 = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    while (p1 < len1 && p2 < len2) {
      if (nums1[p1] > nums2[p2]) {
        p2++;
      } else if (nums1[p1] < nums2[p2]) {
        p1++;
      } else {
        res.push_back(nums1[p1]);
        p1++;
        p2++;
      }
    }
    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums1 = {{1, 2, 2, 1}, {4, 9, 5}};
  vector<vector<int>> testNums2 = {{2, 2}, {9, 4, 9, 8, 4}};
  size_t nTest = testNums1.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums1 = " << intVectorToString(testNums1[i])
         << ", nums2 = " << intVectorToString(testNums2[i]) << endl;
    // Call the Solution function here!
    vector<int> ans = Solution().intersect(testNums1[i], testNums2[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(ans) << endl;
    cout << "===========" << endl;
  }
}
