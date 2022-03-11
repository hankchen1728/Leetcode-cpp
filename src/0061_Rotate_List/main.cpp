#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return nullptr;

    int lLen = 1;
    ListNode* tail = head;
    while (tail->next != nullptr) {
      tail = tail->next;
      ++lLen;
    }

    k %= lLen;

    // handling the case that "k" is larger than number of nodes
    tail->next = head;

    // get the new tail after k-times rotation
    tail = head;
    while (++k < lLen) tail = tail->next;

    head = tail->next;     // new head
    tail->next = nullptr;  // ending the new tail

    return head;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<vector<int>, int>> testCase = {
      {{1, 2, 3, 4, 5}, 2},  // [4,5,1,2,3]
      {{0, 1, 2}, 4},        // [2,0,1]
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
    ListNode* res = Solution().rotateRight(head, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << listNodeToString(res) << endl;
    cout << "===========" << endl;
  }
}
