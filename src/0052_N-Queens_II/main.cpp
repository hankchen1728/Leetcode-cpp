#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution
{
 private:
  int cnt;
  int nQueens;
  std::unique_ptr<int8_t[]> queenCols;

 public:
  int totalNQueens(int n)
  {
    cnt = 0;
    nQueens = n;
    queenCols = std::make_unique<int8_t[]>(n);
    memset(queenCols.get(), -1, n * sizeof(decltype(*queenCols.get())));

    for (int i = 0; i < n; ++i) backtracking(0, i);

    return cnt;
  }

  void backtracking(int row, int col)
  {
    // check if current position is valid
    for (int r = 0; r < row; ++r)
    {
      if (queenCols[r] == col || abs(queenCols[r] - col) == row - r) return;
    }

    if (row == nQueens - 1)
    {
      ++cnt;
    }
    else
    {
      // go to next row
      queenCols[row] = col;
      row += 1;

      for (int c = 0; c < nQueens; ++c) backtracking(row, c);

      queenCols[row - 1] = -1;
    }
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
    cout << Bold("Example " + to_string(i + 1) + ":") << endl;
    // print the test case input here!
    cout << Bold("Input: ") << testCase[i] << endl;
    // Call the Solution function here!
    int res = Solution().totalNQueens(testCase[i]);
    cout << Bold("Output: ") << res << endl;
    cout << "===========" << endl;
  }
}
