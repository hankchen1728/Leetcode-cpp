#include <iostream>
#include <string>
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1);  // pointer of the head node
    ListNode* curr = head;              // pointer of current position

    int sum = 0;
    while (l1 || l2) {
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }

      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }

      curr->next = new ListNode(sum % 10);
      curr = curr->next;
      sum /= 10;
    }
    // check residual
    if (sum) {
      curr->next = new ListNode(sum);
    }

    return head->next;
  }
};
// Solution end

// main
int main() {
  // Create test case
  vector<vector<int>> l1_vectors{
    {2, 4, 3},
    {0},
    {9, 9, 9, 9, 9, 9, 9}
  };

  vector<vector<int>> l2_vectors{
    {5, 6, 4},
    {0},
    {9, 9, 9, 9}
  };
  size_t numCases = 3;

  for (size_t i_test = 0; i_test < numCases; i_test++) {
    ListNode* l1 = vectorToListNode(l1_vectors[i_test]);
    ListNode* l2 = vectorToListNode(l2_vectors[i_test]);

    ListNode* sum = Solution().addTwoNumbers(l1, l2);

    // Output part
    cout << "Example " << i_test << endl;
    cout << "Input: l1 = " << intVectorToString(l1_vectors[i_test])
         << ", l2 = " << intVectorToString(l2_vectors[i_test]) << endl;
    cout << "Output: " << listNodeToString(sum) << endl;
    cout << "===================" << endl;
  }
}
