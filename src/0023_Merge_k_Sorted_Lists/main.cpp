#include <iostream>
#include <queue>
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

  struct nodeCmp {
    bool operator()(ListNode* l1, ListNode* l2) { return l1->val > l2->val; }
  };

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return nullptr;

    ListNode *dummy = new ListNode(0), *curr = dummy;

    // create priority queue
    priority_queue<ListNode*, vector<ListNode*>, nodeCmp> pq;
    for (ListNode* l : lists) {
      if (l) pq.push(l);
    }

    while (!pq.empty()) {
      // insert the top element to merged list
      curr->next = pq.top();
      curr = curr->next;
      pq.pop();

      // push the next node of top element to the heap
      if (curr->next != nullptr) {
        pq.push(curr->next);
      }
    }

    return dummy->next;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<vector<int>>> testCase = {
      {{1, 4, 5}, {1, 3, 4}, {2, 6}}, {}, {{}}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m " << int2dVectorToString(testCase[i]) << endl;
    // create the input linked lists
    vector<ListNode*> lists;
    for (vector<int>& arr : testCase[i]) {
      lists.push_back(intVectorToListNode(arr));
    }
    // Running the algorithm
    ListNode* head = Solution().mergeKLists(lists);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << listNodeToString(head) << endl;
    cout << "===========" << endl;
  }
}
