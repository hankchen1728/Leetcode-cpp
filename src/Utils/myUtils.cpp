#include <iomanip>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include "myUtils.h"

string int2dVectorToString(const vector<vector<int>>& values)
{
  return int2dVectorToString(values, false);
}

string int2dVectorToString(const vector<vector<int>>& values,
                           bool pretty = false)
{
  size_t rows = values.size();
  string result;

  for (size_t i = 0; i < rows; i++)
  {
    if (i > 0) result += " ";
    result += intVectorToString(values[i]) + ",";
    if (pretty && i < rows - 1) result += "\n";
  }
  return "[" + result.substr(0, result.length() - 1) + "]";
}

string intVectorToString(const vector<int>& nums)
{
  return intVectorToString(nums, -1);
}

string intVectorToString(const vector<int>& nums, int length = -1)
{
  if (length == -1) length = nums.size();
  if (length == 0) return "[]";

  string result;
  for (const int& num : nums)
  {
    result += to_string(num) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

string charVectorToString(vector<char>& s)
{
  stringstream ss;
  ss << "[";

  for (size_t i = 0; i < s.size(); ++i)
  {
    ss << "\"" << s[i] << "\"";
    if (i + 1 < s.size()) ss << ", ";
  }
  ss << "]";

  return ss.str();
}

string stringVectorToString(vector<string>& strings)
{
  stringstream ss;
  ss << "[";

  for (size_t i = 0; i < strings.size(); ++i)
  {
    ss << quoted(strings[i]);
    if (i + 1 < strings.size()) ss << ", ";
  }
  ss << "]";

  return ss.str();
}

ListNode* intVectorToListNode(vector<int>& nums)
{
  ListNode* head = new ListNode(-1);
  ListNode* curr = head;

  for (const int& i : nums)
  {
    curr->next = new ListNode(i);
    curr = curr->next;
  }

  return head->next;
}

string listNodeToString(ListNode* node)
{
  string result;
  ListNode* curr = node;

  while (curr)
  {
    int val = curr->val;
    result += to_string(val) + ",";
    curr = curr->next;
  }

  return "[" + result.substr(0, result.length() - 1) + "]";
}
