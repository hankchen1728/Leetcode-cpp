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
    // check if one of the list is empty
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    // if (l1->val > l2->val) return mergeTwoLists(l2, l1);

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

    if (l1 != nullptr)
      curr->next = l1;
    else if (l2 != nullptr)
      curr->next = l2;

    return root->next;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testL1s = {{1, 2, 4}, {}, {}};
  vector<vector<int>> testL2s = {{1, 3, 4}, {}, {0}};
  size_t nTest = testL1s.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "l1 = " << intVectorToString(testL1s[i])
         << ", l2 = " << intVectorToString(testL2s[i]) << endl;
    // Call the Solution function here!
    ListNode* res = Solution().mergeTwoLists(intVectorToListNode(testL1s[i]),
                                             intVectorToListNode(testL2s[i]));
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << listNodeToString(res) << endl;
    cout << "===========" << endl;
  }
}
