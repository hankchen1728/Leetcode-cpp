#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Solution begin
class Solution {
 public:
  bool isValidSerialization(string preorder) {
    istringstream inStm(preorder);
    string node;  // parsed value for current node
    // if there are `n` non-null node, there it requires `n+1` null node
    int allowNull = 1;

    bool attachRoot = false;
    while (getline(inStm, node, ',')) {
      if (attachRoot) return false;
      if (node == "#") {
        allowNull--;
        if (allowNull == 0) {
          // if no more null are allowed, i.e. attach parents of root
          // then no more node is allowed
          attachRoot = true;
        }
      } else {
        allowNull++;
      }
    }
    return (bool)allowNull == 0;
  }
};
// Solution end

int main() {
  string testPreOrders[3] = {"9,3,4,#,#,1,#,#,2,#,6,#,#", "1,#", "9,#,#,1"};

  for (size_t iTest = 0; iTest < 3; iTest++) {
    cout << "Example " << iTest + 1 << ":" << endl;
    cout << "Input: preorder = \"" << testPreOrders[iTest] << "\"" << endl;
    string result = Solution().isValidSerialization(testPreOrders[iTest])
                        ? "true"
                        : "false";
    cout << "Output: " << result << endl;
    cout << "==================" << endl;
  }
}
