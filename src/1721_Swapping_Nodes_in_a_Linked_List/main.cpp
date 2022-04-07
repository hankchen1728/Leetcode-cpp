#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  // Solution() {
  //   // Speed up
  //   ios::sync_with_stdio(false);
  //   cin.tie(nullptr);
  //   cout.tie(nullptr);
  // }
  ListNode* swapNodes(ListNode* head, int k) {
    // return swapNodes_byNode(head, k);
    return swapNodes_byVal(head, k);
  }

  ListNode* swapNodes_byNode(ListNode* head, int k) {
    ListNode* root = new ListNode(0);
    ListNode *fast = root, *slow = root;
    root->next = head;

    // extract the (k-1) position for swap
    // for (int i = 1; i < k; ++i) fast = fast->next;
    while (--k > 0) fast = fast->next;

    // extract the (Len-k) position for swap
    ListNode* tmp = fast->next;
    while (tmp->next) {
      tmp = tmp->next;
      slow = slow->next;
    }

    // swap "fast->next" and "slow->next"
    tmp = fast->next;
    fast->next = slow->next;
    slow->next = tmp;
    tmp = fast->next->next;
    fast->next->next = slow->next->next;
    slow->next->next = tmp;

    return root->next;
  }

  ListNode* swapNodes_byVal(ListNode* head, int k) {
    ListNode *fast = head, *slow = head;

    // extract the k position for swap
    while (--k > 0) fast = fast->next;

    // extract the (Len-k+1) position for swap
    ListNode* tmp = fast->next;
    while (tmp) {
      tmp = tmp->next;
      slow = slow->next;
    }

    // swap fast and slow
    if (fast->val != slow->val) {
      fast->val ^= slow->val;
      slow->val ^= fast->val;
      fast->val ^= slow->val;
    }

    return head;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<vector<int>, int>> testCase = {
      {{1, 2, 3, 4, 5}, 2},                 // [1,4,3,2,5]
      {{7, 9, 6, 6, 7, 8, 3, 0, 9, 5}, 5},  // [7,9,6,6,8,7,3,0,9,5]
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m head = " << intVectorToString(testCase[i].first)
         << ", k = " << testCase[i].second << endl;
    // Call the Solution function here!
    ListNode* head = intVectorToListNode(testCase[i].first);
    ListNode* res = Solution().swapNodes(head, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << listNodeToString(res) << endl;
    cout << "===========" << endl;
  }
}
