#include "myUtils.h"

string intVectorToString(vector<int> nums) {
  return intVectorToString(nums, -1);
}

string intVectorToString(vector<int> nums, int length = -1) {
  if (length == -1) {
    length = nums.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = nums[index];
    result += to_string(number) + ",";
  }
  return "[" + result.substr(0, result.length() - 1) + "]";
}
