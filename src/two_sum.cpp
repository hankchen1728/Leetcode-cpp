#include <sys/_types/_size_t.h>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // create a vector of size 2 to store answer
    vector<int> idx_pair(2, -1);
    // create a map for recording index
    unordered_map<int, int> idx_map;
    int numSize = nums.size(), res;

    for (int i = 0; i < numSize; i++) {
      res = target - nums.at(i);
      // check if the residual is in the mapping
      if (idx_map[res]) {
        idx_pair.at(0) = idx_map[res] - 1;
        idx_pair.at(1) = i;
        break;
      } else {
        // add current number to recording map
        idx_map[nums.at(i)] = i + 1;  // avoid 0 == false
      }
    }

    return idx_pair;
  }
};

// Utility functions
string integerVectorToString(vector<int> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

// main
int main() {
  // create test cases
  vector<vector<int>> testNums{
      {2, 7, 11, 15},
      {3, 2, 4},
      {3, 3}
  };
  vector<int> testTarget{9, 6, 6};
  size_t numCases = 3;

  // running algorithm
  for (size_t i_test = 0; i_test < numCases; i_test++) {
    vector<int> ret = Solution().twoSum(testNums[i_test], testTarget[i_test]);
    cout << "Test case" << i_test << endl;
    cout << "Input: nums = " << integerVectorToString(testNums[i_test]) ;
    cout << ", target = " << testTarget[i_test] << endl;
    cout << "Output:" << integerVectorToString(ret) << endl;
    cout << "========================" << endl;
  }
}
