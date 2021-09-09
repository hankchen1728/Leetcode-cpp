#include <iostream>
#include <stack>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Utility Functions
ListNode* vectorToListNode(vector<int> nums) {
  ListNode* head = new ListNode(-1);
  ListNode* curr = head;

  for (const int& i : nums) {
    curr->next = new ListNode(i);
    curr = curr->next;
  }

  return head->next;
}

string listNodeToString(ListNode* node) {
  string result;
  ListNode* curr = node;

  while (curr) {
    int val = curr->val;
    result += to_string(val) + ",";
    curr = curr->next;
  }

  return "[" + result.substr(0, result.length() - 1) + "]";
}

// Solution begin
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    // empty or only one element, just return original list
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode* curr;
    ListNode* reversed = head;  // head of reversed list

    while (head->next != nullptr) {
      curr = head->next;
      // since the next one will be moved to first
      // the current next one will be the next next one
      head->next = head->next->next;
      curr->next = reversed;
      reversed = curr;
    }
    return reversed;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testHeads{{1, 2, 3, 4, 5}, {1, 2}, {}};

  size_t nTest = testHeads.size();

  for (size_t i = 0; i < nTest; i++) {
    ListNode* head = vectorToListNode(testHeads[i]);
    cout << "Example " << i + 1 << ":" << endl;
    cout << "Input: head = " << intVectorToString(testHeads[i]) << endl;
    ListNode* reversed = Solution().reverseList(head);
    cout << "Output: " << listNodeToString(reversed) << endl;
    cout << "===========" << endl;
  }
}
