#include <iostream>
#include <unordered_set>
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

  bool hasCycle(ListNode* head) { return _hasCycle_TwoPointer(head); }

  bool _hasCycle_TwoPointer(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return false;

    ListNode *slow = head, *fast = head;

    while (fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) return true;
    }

    return slow == fast;
  }

  bool _hasCycle_hashTable(ListNode* head) {
    unordered_set<ListNode*> nodeSet;

    while (head != nullptr) {
      if (nodeSet.count(head) > 0) {
        return true;
      }
      nodeSet.insert(head);
      head = head->next;
    }
    return false;
  }
};
// Solution end

ListNode* makeCycleList(vector<int>& nums, int pos) {
  ListNode* head = intVectorToListNode(nums);

  ListNode *tmp = head, *cycleHead = nullptr;
  if (pos >= 0) {
    while (pos-- >= 0) tmp = tmp->next;
    cycleHead = tmp;
  }

  while (tmp->next != nullptr) tmp = tmp->next;
  tmp->next = cycleHead;

  return head;
}

int main() {
  // Setting the test cases
  vector<pair<vector<int>, int>> testCase = {
      {{3, 2, 0, -4}, 1},     // true
      {{1, 2}, 0},            // true
      {{1}, -1},              // false
      {{1, 2, 3, 4, 5}, -1},  // false
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m head = " << intVectorToString(testCase[i].first)
         << ", pos = " << testCase[i].second << endl;
    // Call the Solution function here!
    ListNode* head = makeCycleList(testCase[i].first, testCase[i].second);
    bool res = Solution().hasCycle(head);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << (res ? "true" : "false") << endl;
    cout << "===========" << endl;
  }
}
