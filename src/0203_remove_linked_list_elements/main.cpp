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
  ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) return head;

    ListNode* prev = head;

    // remove all the occurrence elements after the head node
    while (prev->next != nullptr) {
      if (prev->next->val == val) {
        prev->next = prev->next->next;
      } else {
        prev = prev->next;
      }
    }

    return (head->val == val) ? head->next : head;
  }
};
// Solution end

int main() {
  // Write something here
  vector<pair<vector<int>, int>> testCase = {
      {{1, 2, 6, 3, 4, 5, 6}, 6}, {{}, 1}, {{7, 7, 7, 7}, 7}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m head = " << intVectorToString(testCase[i].first)
         << ", val = " << testCase[i].second << endl;
    // Call the Solution function here!
    ListNode* res = Solution().removeElements(
        intVectorToListNode(testCase[i].first), testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << listNodeToString(res) << endl;
    cout << "===========" << endl;
  }
}
