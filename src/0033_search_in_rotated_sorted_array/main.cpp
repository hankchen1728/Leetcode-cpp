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

  int search(vector<int>& nums, int target) {
    int left = 0, len = nums.size(), right = len - 1, mid;

    while (left <= right) {
      mid = left + (right - left) / 2;
      // found
      if (nums[mid] == target) return mid;

      if (nums[mid] > nums.back()) {
        // left half is sorted (or ordered)
        if (nums[left] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        // right half is sorted
        if (nums[mid] < target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return -1;
  }

  // method2: bad method
  int search2(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, mid, len = nums.size();
    // find the minimum
    while (left < right) {
      mid = (left + right) / 2;
      if (nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    // now `nums[left]` is the minimum
    int pMax = (left - 1 + len) % len;
    if (target < nums[left] || target > nums[pMax] ||
        (target > nums.back() && target < nums[0])) {
      return -1;
    } else if (target <= nums.back()) {
      // right half
      right = len - 1;
    } else {
      // left half
      right = pMax;
      left = 0;
    }

    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        return mid;
      }
    }

    return -1;
  }
};
// Solution end

int main() {
  // Write something here
  vector<pair<vector<int>, int>> testCase = {{{4, 5, 6, 7, 0, 1, 2}, 0},
                                             {{4, 5, 6, 7, 0, 1, 2}, 3},
                                             {{1}, 1},
                                             {{1, 3}, 2},
                                             {{3, 1}, 3},
                                             {{3, 1}, 1},
                                             {{5, 3}, 4},
                                             {{4, 5, 6, 7, 0, 1, 2}, 6}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i].first)
         << ", target = " << testCase[i].second << endl;
    // Call the Solution function here!
    int res = Solution().search(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
