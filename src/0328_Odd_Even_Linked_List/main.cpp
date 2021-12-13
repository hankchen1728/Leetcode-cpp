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
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    // hold the first even node
    ListNode* evenRoot = head->next;
    ListNode *oddCurr = head, *evenCurr = evenRoot;

    while (evenCurr && evenCurr->next) {
      oddCurr->next = evenCurr->next;
      oddCurr = oddCurr->next;

      evenCurr->next = oddCurr->next;
      evenCurr = evenCurr->next;
    }

    oddCurr->next = evenRoot;

    return head;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {
      {1, 2, 3, 4, 5}, {2, 1, 3, 5, 6, 4, 7}, {}, {0}, {1, 2, 3, 4, 5, 6},
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m head = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    ListNode* res = Solution().oddEvenList(intVectorToListNode(testCase[i]));
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << listNodeToString(res) << endl;
    cout << "===========" << endl;
  }
}
