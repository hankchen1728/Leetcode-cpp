#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

int PICK = 0;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num) { return num > PICK ? -1 : (num < PICK); }

// Solution begin
class Solution {
 public:
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  int guessNumber(int n) {
    int L = 1, R = n, mid, cond;

    while (L < R) {
      mid = ((long)L + (long)R + 1) / 2;
      cond = guess(mid);
      switch (cond) {
        case 1:
          L = mid + 1;
          break;
        case -1:
          R = mid - 1;
          break;
        case 0:
          return mid;
      }
    }
    return L;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<int, int>> testCase = {
      {10, 6},  // 6
      {1, 1},   // 1
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    int n = testCase[i].first;
    PICK = testCase[i].second;
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    printf("Input:\e[0m  n = %d, pick = %d\n", n, PICK);
    // Call the Solution function here!
    int res = Solution().guessNumber(n);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
};
