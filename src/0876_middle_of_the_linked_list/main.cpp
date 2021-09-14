#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

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
  ListNode* middleNode(ListNode* head) {
    ListNode *mid = head, *front = head;

    while (front != nullptr && front->next != nullptr) {
      front = front->next->next;
      mid = mid->next;
    }
    return mid;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testCase = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5, 6}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "head = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    ListNode* mid = Solution().middleNode(intVectorToListNode(testCase[i]));
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << listNodeToString(mid) << endl;
    cout << "===========" << endl;
  }
}
