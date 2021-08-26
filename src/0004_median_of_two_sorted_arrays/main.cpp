#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  // Method 1: binary search
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    // Ensure that `nums1` is the longer one
    if (m < n) return findMedianSortedArrays(nums2, nums1);

    // If the shorter one is empty, then the answer is exactly
    // the median of the longer one
    if (n == 0)
      return ((double)nums1[(m - 1) / 2] + (double)nums1[m / 2]) / 2.0;

    // Search the two "cut position": `mid1` and `mid2` of the given two vectors
    int left = 0, right = n * 2;
    while (left <= right) {
      int mid2 = (left + right) / 2;
      int mid1 = m + n - mid2;
      double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
      double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
      double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
      double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];

      if (L1 > R2)
        // The `R2` is too small
        // move the cut position `mid2` of `num2` right
        left = mid2 + 1;
      else if (L2 > R1)
        // The `L2` is too large
        // move the cut position `mid2` of `num2` left
        right = mid2 - 1;
      else
        return (max(L1, L2) + min(R1, R2)) / 2;
    }
    return -1;
  }

  // method 2: merge the two sorted vectors
  double _findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    size_t len1 = nums1.size(), len2 = nums2.size(), len = len1 + len2;
    // Only need to sort the numbers lower than or equal to the median
    // i.e. the half merged array
    vector<int> mergedNums(len / 2 + 1);
    vector<int>::iterator ptr1 = nums1.begin(), ptr2 = nums2.begin();

    size_t iMerged = 0;
    while (iMerged < mergedNums.size() &&
           (ptr1 < nums1.end() && ptr2 < nums2.end())) {
      if (*ptr1 > *ptr2) {
        mergedNums[iMerged] = *(ptr2++);
      } else
        mergedNums[iMerged] = *(ptr1++);
      iMerged++;
    }

    while (ptr1 < nums1.end() && iMerged < mergedNums.size()) {
      mergedNums[iMerged] = *(ptr1++);
      iMerged++;
    }

    while (ptr2 < nums2.end() && iMerged < mergedNums.size()) {
      mergedNums[iMerged] = *(ptr2++);
      iMerged++;
    }

    return (double)(mergedNums[len / 2] + mergedNums[(len - 1) / 2]) / 2;
  }
};
// Solution end

int main() {
  vector<vector<int>> testNums1 = {{1, 3}, {1, 2}, {0, 0}, {}, {1}};
  vector<vector<int>> testNums2 = {{2}, {3, 4}, {0, 0}, {1}, {}};
  size_t nCases = testNums1.size();

  for (size_t iCase = 0; iCase < nCases; iCase++) {
    cout << "Example " << iCase + 1 << endl;
    cout << "Input: nums1 = " << intVectorToString(testNums1[iCase])
         << ", nums2 = " << intVectorToString(testNums2[iCase]) << endl;
    double ans =
        Solution().findMedianSortedArrays(testNums1[iCase], testNums2[iCase]);
    cout << "Output: " << ans << endl;
    cout << "========================" << endl;
  }
}
