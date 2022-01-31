#include <climits>
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
  ListNode* insertionSortList(ListNode* head) {
    ListNode* root = new ListNode(INT_MIN, head);  // dummy head
    ListNode* curr = head->next;  // current node for each iteration

    while (curr != nullptr) {
      // check if current node need to be change place
      if (curr->val < head->val) {
        // search the insertion place
        ListNode* prev = root;
        while (prev->next->val < curr->val) prev = prev->next;

        head->next = head->next->next;
        curr->next = prev->next;
        prev->next = curr;
      } else {
        head = head->next;
      }

      // move to next node
      curr = head->next;
    }
    return root->next;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {{4, 2, 1, 3}, {-1, 5, 3, 4, 0}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m head = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    ListNode* res =
        Solution().insertionSortList(intVectorToListNode(testCase[i]));
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << listNodeToString(res) << endl;
    cout << "===========" << endl;
  }
}
