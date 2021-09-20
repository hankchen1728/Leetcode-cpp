#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// utilize functions
Node* buildPBT(vector<int>& nodeVals) {
  // no node
  if (nodeVals.empty()) return nullptr;

  Node *root = new Node(nodeVals[0]), *curr = root;
  queue<Node*> nodes;
  nodes.push(root);

  size_t i_node = 0;

  while (i_node < nodeVals.size() - 1) {
    curr = nodes.front();
    nodes.pop();
    curr->left = new Node(nodeVals[++i_node]);
    curr->right = new Node(nodeVals[++i_node]);
    nodes.push(curr->left);
    nodes.push(curr->right);
  }
  return root;
}

string PBTtoString(Node* root) {
  Node *layerHead = root, *curr;
  string res = "[";

  while (layerHead != nullptr) {
    curr = layerHead;
    while (curr != nullptr) {
      res += (to_string(curr->val) + ",");
      curr = curr->next;
    }
    res += "#,";
    layerHead = layerHead->left;
  }
  if (res.length() > 1)
    res[res.size() - 1] = ']';
  else
    res += ']';
  return res;
}

// Solution begin
class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr || root->left == nullptr) return root;

    // cout << root->val << " ";
    root->left->next = root->right;
    if (root->next != nullptr) {
      root->right->next = root->next->left;
    }
    root->left = connect(root->left);
    root->right = connect(root->right);

    return root;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testRoots = {
      {1, 2, 3, 4, 5, 6, 7},
      {},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}};
  size_t nTest = testRoots.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "root = " << intVectorToString(testRoots[i]) << endl;
    Node* root = buildPBT(testRoots[i]);
    root = Solution().connect(root);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << PBTtoString(root) << endl;
    cout << "===========" << endl;
  }
}
