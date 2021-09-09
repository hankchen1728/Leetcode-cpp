#include "myUtils.h"

string int2dVectorToString(const vector<vector<int>>& values) {
  size_t rows = values.size();
  string result;

  for (size_t i = 0; i < rows; i++) {
    result += intVectorToString(values[i]) + ",";
  }
  return "[" + result.substr(0, result.length() - 1) + "]";
}

string intVectorToString(const vector<int>& nums) {
  return intVectorToString(nums, -1);
}

string intVectorToString(const vector<int>& nums, int length = -1) {
  if (length == -1) length = nums.size();
  if (length == 0) return "[]";

  string result;
  for (int index = 0; index < length; index++) {
    int number = nums[index];
    result += to_string(number) + ",";
  }
  return "[" + result.substr(0, result.length() - 1) + "]";
}
