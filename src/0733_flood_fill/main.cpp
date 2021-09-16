#include <iostream>
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
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor == newColor) return image;
    paintPixel(image, sr, sc, oldColor, newColor);
    return image;
  }

  void paintPixel(vector<vector<int>>& image, int sr, int sc, int oldColor,
                  int newColor) {
    if (image[sr][sc] == oldColor) {
      image[sr][sc] = newColor;
      if (sr >= 1) paintPixel(image, sr - 1, sc, oldColor, newColor);
      if (sc >= 1) paintPixel(image, sr, sc - 1, oldColor, newColor);
      if (sr < image.size() - 1)
        paintPixel(image, sr + 1, sc, oldColor, newColor);
      if (sc < image[0].size() - 1)
        paintPixel(image, sr, sc + 1, oldColor, newColor);
    }
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<vector<int>>> testImgs = {
      {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}},
      {{0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 1, 1}},
      {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}, {1, 0, 0, 1}}};
  vector<int> testSr = {1, 0, 1, 1};
  vector<int> testSc = {1, 0, 1, 1};
  vector<int> testNewC = {2, 2, 1, 2};
  size_t nTest = testImgs.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "image = " << int2dVectorToString(testImgs[i])
         << ", sr = " << testSr[i] << ", sc = " << testSc[i]
         << ", newColor = " << testNewC[i] << endl;
    // Call the Solution function here!
    vector<vector<int>> newImg =
        Solution().floodFill(testImgs[i], testSr[i], testSc[i], testNewC[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(newImg) << endl;
    cout << "===========" << endl;
  }
}
