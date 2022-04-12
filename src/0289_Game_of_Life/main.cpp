#include <iostream>
#include <vector>

#include "myUtils.h"

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
  void gameOfLife(vector<vector<int>>& board) {
    int8_t M = board.size(), N = board[0].size();
    vector<vector<int8_t>> directs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    // recording status of neighbors
    for (int8_t i = 0; i < M; ++i) {
      for (int8_t j = 0; j < N; ++j) {

        if (board[i][j] % 2) {
          int8_t nb_i, nb_j;

          // 8 neighbors (8 directions)
          for (const vector<int8_t>& d : directs) {
            // add current living info. to neighbors
            nb_i = i + d[0], nb_j = j + d[1];

            if ((0 <= nb_i && nb_i < M) && (0 <= nb_j && nb_j < N)) {
              board[nb_i][nb_j] += 2;
            }
          }
        }
      }
    }

    // conditioning next stage
    for (int8_t i = 0; i < M; ++i) {
      for (int8_t j = 0; j < N; ++j) {
        // number of living neighbors
        int8_t live_nb = board[i][j] / 2;

        if (board[i][j] % 2) {
          // current cell is "live"

          if (live_nb < 2 || live_nb > 3) {
            board[i][j] = 0;
          } else {
            board[i][j] = 1;
          }
        } else {
          // current cell is "dead"

          if (live_nb == 3) {
            board[i][j] = 1;
          } else {
            board[i][j] = 0;
          }
        }
      }
    }

    return;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<vector<int>>> testCase = {
      {{0, 1, 0},
       {0, 0, 1},
       {1, 1, 1},
       {0, 0, 0}},       // [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
      {{1, 1}, {1, 0}},  // [[1,1],[1,1]]
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m board = " << int2dVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    Solution().gameOfLife(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(testCase[i]) << endl;
    cout << "===========" << endl;
  }
}
