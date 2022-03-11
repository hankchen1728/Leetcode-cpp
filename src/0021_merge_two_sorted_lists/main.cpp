#include <iostream>
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

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // return _mergeTwoLists_iterative(l1, l2);
    return _mergeTwoLists_recursive(l1, l2);
  }

  ListNode* _mergeTwoLists_recursive(ListNode* l1, ListNode* l2) {
    // check if one of the list is empty
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    if (l1->next < l2->next) {
      l1->next = _mergeTwoLists_recursive(l1->next, l2);
      return l1;
    } else {
      l2->next = _mergeTwoLists_recursive(l2->next, l1);
      return l2;
    }

    return nullptr;
  }

  ListNode* _mergeTwoLists_iterative(ListNode* l1, ListNode* l2) {
    // check if one of the list is empty
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode* root = new ListNode();
    ListNode* curr = root;
    while (l1 != nullptr && l2 != nullptr) {
      if (l2->val >= l1->val) {
        curr->next = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }

    // connect the remaining nodes
    curr->next = (l1 != nullptr) ? l1 : l2;

    return root->next;
  }
};
// Solution end

int main() {
  // Write something here
  vector<pair<vector<int>, vector<int>>> testPairs = {
      {{1, 2, 4}, {1, 3, 4}},  // [1,1,2,3,4,4]
      {{}, {}},                // []
      {{}, {0}},               // [0]
  };
  size_t nTest = testPairs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "l1 = " << intVectorToString(testPairs[i].first)
         << ", l2 = " << intVectorToString(testPairs[i].second) << endl;
    // Call the Solution function here!
    ListNode* res =
        Solution().mergeTwoLists(intVectorToListNode(testPairs[i].first),
                                 intVectorToListNode(testPairs[i].second));
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << listNodeToString(res) << endl;
    cout << "===========" << endl;
  }
}
