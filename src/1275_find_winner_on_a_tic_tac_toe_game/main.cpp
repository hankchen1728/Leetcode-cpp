#include <cstdint>
#include <iostream>
#include <string>
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
  string tictactoe(vector<vector<int>>& moves) {
    vector<vector<uint8_t>> gridCnt(2, vector<uint8_t>(8, 0));
    vector<int> move;
    size_t iPlayer;
    for (size_t i = 0; i < moves.size(); i++) {
      move = moves[i];
      iPlayer = i % 2;
      // row
      if (++gridCnt[iPlayer][move[0]] == 3) return iPlayer ? "B" : "A";
      // column
      if (++gridCnt[iPlayer][move[1] + 3] == 3) return iPlayer ? "B" : "A";

      // first diag
      if (move[0] == move[1]) {
        if (++gridCnt[iPlayer][6] == 3) return iPlayer ? "B" : "A";
      }
      // second diag
      if ((move[0] + move[1]) == 2) {
        if (++gridCnt[iPlayer][7] == 3) return iPlayer ? "B" : "A";
      }
    }
    if (moves.size() == 9) return "Draw";

    return "Pending";
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<vector<int>>> testMoves = {
      {{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}},
      {{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}},
      {{0, 0}, {1, 1}, {2, 0}, {1, 0}, {1, 2}, {2, 1}, {0, 1}, {0, 2}, {2, 2}},
      {{0, 0}, {1, 1}}};
  size_t nTest = testMoves.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "moves = " << int2dVectorToString(testMoves[i]) << endl;
    // Call the Solution function here!
    string res = Solution().tictactoe(testMoves[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m "
         << "\"" << res << "\"" << endl;
    cout << "===========" << endl;
  }
}
