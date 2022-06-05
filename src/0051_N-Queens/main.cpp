#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution
{
 private:
  vector<vector<string>> chessBoards;
  int nQueens;

 public:
  Solution()
  {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }

  vector<vector<string>> solveNQueens(int n)
  {
    nQueens = n;
    vector<string> board(n, string(n, '.'));

    for (int c = 0; c < n; ++c) backtracking(0, c, board);

    return chessBoards;
  }

  void backtracking(int row, int col, vector<string>& board)
  {
    // check current queen is valid or not
    for (int move = 1; move <= row; ++move)
    {
      string* p_row = &(board[row - move]);
      // current column
      if ((*p_row)[col] == 'Q') return;
      // left-up line
      if (col >= move && (*p_row)[col - move] == 'Q') return;
      // right-up line
      if (col + move < nQueens && (*p_row)[col + move] == 'Q') return;
    }

    board[row][col] = 'Q';
    if (row == nQueens - 1)
    {
      chessBoards.push_back(board);
    }
    else
    {
      // go to next row
      row += 1;
      for (int c = 0; c < col - 1; ++c) backtracking(row, c, board);
      for (int c = col + 2; c < nQueens; ++c) backtracking(row, c, board);
      row -= 1;
    }
    board[row][col] = '.';

    return;
  }
};
// Solution end

int main()
{
  cout << "\n===========" << endl;

  // Setting the test cases
  vector<int> testCase = {4, 1};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++)
  {
    // print the test case input here!
    cout << Bold("Example " + to_string(i + 1) + ":") << endl;
    cout << Bold("Input: ") << testCase[i] << endl;

    // Call the Solution function here!
    vector<vector<string>> res = Solution().solveNQueens(testCase[i]);
    cout << Bold("Output: ") << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << stringVectorToString(res[i]);
      ;
      if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "===========" << endl;
  }
}
