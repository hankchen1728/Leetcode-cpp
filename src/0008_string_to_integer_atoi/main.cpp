#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Solution begin
class Solution {
 public:
  Solution() {
    // Speedup
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int myAtoi(string s) {
    // Step1. remove all leading whitespace
    size_t pos = 0, len = s.length();
    while (pos < len && s[pos] == ' ') pos++;

    // Step2. Check if the next character is sign
    // ascii code of '+' and '-' are 43 and 45 respectively
    bool neg = false;
    if (s[pos] == 45 || s[pos] == 43) {
      if (s[pos] == 45) neg = true;
      pos++;
    }

    // Step4. Convert these digits into an integer
    int num = 0;
    while (pos < len && (s[pos] >= 48 && s[pos] <= 57)) {
      if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[pos] > 55)) {
        return neg ? INT_MIN : INT_MAX;
      }
      num = num * 10 + (s[pos] - 48);
      pos++;
    }
    if (neg) num *= -1;

    return num;
  }
};
// Solution end

int main() {
  // Write something here
  vector<string> testCase = {"42", "   -42", "4193 with words", "words and 987",
                             "-91283472332"};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "s = \"" << testCase[i] << "\"" << endl;
    // Call the Solution function here!
    int ans = Solution().myAtoi(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
