#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
typedef pair<int, uint16_t> FREQ_PAIR;

class PAIR_Great {
 public:
  bool operator()(FREQ_PAIR p1, FREQ_PAIR p2) { return p1.second > p2.second; }
};

class Solution {
 public:
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  vector<int> topKFrequent(vector<int>& nums, int k) {
    // create a hash map for recording frequency
    unordered_map<int, uint16_t> freq_mp;
    for (const int& n : nums) ++freq_mp[n];

    priority_queue<FREQ_PAIR, vector<FREQ_PAIR>, PAIR_Great> pq;
    for (pair<const int, uint16_t>& p : freq_mp) {
      pq.push(p);
      if (pq.size() > k) pq.pop();
    }

    vector<int> res;
    res.reserve(k);

    while (k-- > 0) {
      res.push_back(pq.top().first);
      pq.pop();
    }

    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<vector<int>, int>> testCase = {
      {{1, 1, 1, 2, 2, 3}, 2},                            // [1, 2]
      {{1}, 1},                                           // [1]
      {{1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 5, 4, 4, 4, 4}, 1}  // [1]
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i].first)
         << ", k = " << testCase[i].second << endl;
    // Call the Solution function here!
    vector<int> res =
        Solution().topKFrequent(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
