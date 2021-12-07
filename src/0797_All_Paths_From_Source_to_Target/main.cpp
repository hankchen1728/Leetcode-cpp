#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 private:
  vector<vector<int>> res;

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    // initial path always start from 0
    vector<int> initPath = {0};

    // Run depth-first search
    DFS(initPath, graph);

    return res;
  }

  void DFS(vector<int>& currPath, vector<vector<int>>& graph) {
    // check if attach end node
    if (currPath.back() == graph.size() - 1) {
      res.push_back(currPath);
      return;
    }

    for (int& n : graph[currPath.back()]) {
      currPath.push_back(n);
      DFS(currPath, graph);
      currPath.pop_back();
    }
    return;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<vector<int>>> testGraphs = {
      {{1, 2}, {3}, {3}, {}},
      {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}},
      {{1}, {}},
      {{1, 2, 3}, {2}, {3}, {}},
      {{1, 3}, {2}, {3}, {}}};
  size_t nTest = testGraphs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m graph = " << int2dVectorToString(testGraphs[i]) << endl;
    // Call the Solution function here!
    vector<vector<int>> res = Solution().allPathsSourceTarget(testGraphs[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
