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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *root = new ListNode(-1, head);
    ListNode *fast = root, *slow = root;
    for (int i = n; i > 0; i--) {
      fast = fast->next;
    }

    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    // remove the n-th node
    slow->next = slow->next->next;

    return root->next;
  }
};
// Solution end

int main() {
  // Add one more test case
  vector<vector<int>> testCase = {{1, 2, 3, 4, 5}, {1}, {1, 2}, {1, 2, 3}};
  vector<int> testN = {2, 1, 1, 3};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "head = " << intVectorToString(testCase[i]) << ", n = " << testN[i]
         << endl;
    // Call the Solution function here!
    ListNode* ans =
        Solution().removeNthFromEnd(intVectorToListNode(testCase[i]), testN[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << listNodeToString(ans) << endl;
    cout << "===========" << endl;
  }
}
