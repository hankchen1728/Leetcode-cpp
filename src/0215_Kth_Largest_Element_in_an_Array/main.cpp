#include <iostream>
#include <utility>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Self implementation of min heap
class MinHeap {
 public:
  MinHeap(int heapSize) : heapSize(heapSize), _size(0) {
    // resize the heap container
    heap.resize(heapSize + 1, 0);
  }

  // Get number of elements in Heap
  int size() { return _size; }

  // Insert a new element into Heap
  void add(int val) {
    // check size
    if (_size >= heapSize) return;

    _size += 1;
    // put the new element to end of array
    heap[_size] = val;

    int curr = _size, parent = curr / 2;
    while (curr > 1 && heap[curr] < heap[parent]) {
      // move current element up
      swap(heap[curr], heap[parent]);
      curr = parent;
      parent /= 2;
    }
  }

  // Delete the top element, with the property of Heap remained unchanged
  void pop() {
    if (_size < 1) return;

    // move the replace the top element by the bottom element
    heap[1] = heap[_size];
    _size -= 1;
    int curr = 1;
    while (curr <= _size / 2) {
      int L = curr * 2, R = L + 1;
      if (heap[curr] > heap[L] || heap[curr] > heap[R]) {
        // get the smaller one of left and right child
        int idx_swap = (heap[L] > heap[R]) ? R : L;
        swap(heap[idx_swap], heap[curr]);
        curr = idx_swap;
      } else
        break;
    }
  }

  // Get the top element of minHeap, i.e. the smallest element
  int top() { return heap[1]; }

 private:
  int heapSize;
  int _size;
  vector<int> heap;
};

// Solution begin
class Solution {
 public:
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  int findKthLargest(vector<int>& nums, int k) {
    // k = min(nums.size(), k);
    MinHeap minheap(k);

    int i = 0;
    for (; i < k; i++) {
      minheap.add(nums[i]);
    }

    for (; i < nums.size(); i++) {
      if (nums[i] > minheap.top()) {
        minheap.pop();
        minheap.add(nums[i]);
      }
    }

    return minheap.top();
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<vector<int>, int>> testCase = {
      {{3, 2, 1, 5, 6, 4}, 2},
      {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4},
      {{3, 2, 3, 1,  2,  4, 5, 5, 6, 7, 7, 8, 2, 3,
        1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6},
       20}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i].first)
         << ", k = " << testCase[i].second << endl;
    // Call the Solution function here!
    int res = Solution().findKthLargest(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
