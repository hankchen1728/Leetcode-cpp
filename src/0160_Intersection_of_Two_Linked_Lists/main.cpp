#include <iostream>
#include <utility>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution
{
 public:
  Solution()
  {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }

  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
  {
    return getIntersectionNodeLenDiff(headA, headB);
  }

  // =============== Method 1 ================ //
  int16_t getListLength(ListNode* list)
  {
    int16_t len = 0;
    while (list != nullptr)
    {
      list = list->next;
      ++len;
    }

    return len;
  }

  ListNode* getIntersectionNodeLenDiff(ListNode* headA, ListNode* headB)
  {
    // count length difference of listA and listB
    int16_t lenDiff = getListLength(headA) - getListLength(headB);

    if (lenDiff > 0)
    {
      while (lenDiff-- > 0) headA = headA->next;
    }
    else
    {
      while (lenDiff++ < 0) headB = headB->next;
    }

    while (headA && headA != headB)
    {
      headA = headA->next;
      headB = headB->next;
    }

    return headA;
  }

  // =============== Method 2 ================ //
  ListNode* getIntersectionNodeCycle(ListNode* headA, ListNode* headB)
  {
    if (!headA || !headB) return nullptr;

    ListNode *pA = headA, *pB = headB;

    while (pA != pB)
    {
      pA = pA ? pA->next : headB;
      pB = pB ? pB->next : headA;
    }

    return pA;
  }
};
// Solution end

int main()
{
  cout << "\n===========" << endl;

  // Setting the test cases
  vector<vector<int>> listAs = {{4, 1, 8, 4, 5}, {1, 9, 1, 2, 4}, {2, 6, 4}};
  vector<vector<int>> listBs = {{5, 6, 1, 8, 4, 5}, {3, 2, 4}, {1, 5}};
  vector<int> skipAs = {2, 3, 3};
  vector<int> skipBs = {3, 1, 2};

  size_t nTest = listAs.size();

  for (size_t i = 0; i < nTest; i++)
  {
    cout << Bold("Example " + to_string(i + 1) + ":") << endl;

    // print the test case input here!
    cout << Bold("Input: ");
    printf("listA = %s, listB = %s, skipA = %d, skipB = %d\n",
           intVectorToString(listAs[i]).c_str(),
           intVectorToString(listBs[i]).c_str(), skipAs[i], skipBs[i]);

    // prepare testcase
    vector<int> intersectArray(listAs[i].begin() + skipAs[i], listAs[i].end());
    ListNode* intersect = intVectorToListNode(intersectArray);

    vector<int> aheadAarray(listAs[i].begin(), listAs[i].begin() + skipAs[i]);
    vector<int> aheadBarray(listBs[i].begin(), listBs[i].begin() + skipBs[i]);
    ListNode* listA = intVectorToListNode(aheadAarray);
    ListNode* listB = intVectorToListNode(aheadBarray);

    ListNode* buf = listA;
    while (buf->next != nullptr) buf = buf->next;
    buf->next = intersect;

    buf = listB;
    while (buf->next != nullptr) buf = buf->next;
    buf->next = intersect;

    // Call the Solution function here!
    ListNode* res = Solution().getIntersectionNode(listA, listB);
    cout << Bold("Output: ") << listNodeToString(res) << endl;
    cout << "===========" << endl;
  }
}
