#include <iostream>
#include <queue>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
typedef priority_queue<int, vector<int>, greater_equal<int>> MIN_HEAP;

class KthLargest {
  MIN_HEAP min_pq;
  int k;

 public:
  KthLargest(int _k, vector<int>& nums) : k(_k) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    min_pq = MIN_HEAP(nums.begin(), nums.end());

    while (min_pq.size() > k) {
      min_pq.pop();
    }
  }

  int add(int val) {
    if (min_pq.size() < k) {
      min_pq.push(val);
    } else if (val > min_pq.top()) {
      min_pq.pop();
      min_pq.push(val);
    }

    return min_pq.top();
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<int> nums = {4, 5, 8, 2};
  KthLargest* obj = new KthLargest(3, nums);

  vector<int> added_vals{3, 5, 10, 9, 4};
  vector<int> return_vals;
  return_vals.reserve(added_vals.size());

  for (const int& n : added_vals) {
    return_vals.push_back(obj->add(n));
  }

  string out_msg = intVectorToString(return_vals);
  out_msg.insert(1, "null,");
  cout << out_msg << endl;
}
