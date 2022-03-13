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

  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    // the second node will be the new head of current sub-list
    ListNode* pNext = head->next;
    // swap the remain nodes
    head->next = swapPairs(pNext->next);
    // swap the current pair
    pNext->next = head;
    return pNext;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {{1, 2, 3, 4}, {}, {1}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m head = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    ListNode* res = Solution().swapPairs(intVectorToListNode(testCase[i]));
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << listNodeToString(res) << endl;
    cout << "===========" << endl;
  }
}
