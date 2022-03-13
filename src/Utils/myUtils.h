#ifndef UTIL_HEADER
#define UTIL_HEADER

#define BOOL2STR(Cond) ((Cond) ? "true" : "false")

#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// Functions for converting 1D integer vector to string
/**
 * Parsing content of an integer vector to string,
 * e.g. "[1,2,3,4,5]"
 *
 * @param nums A vector of integer.
 * @return string of content of `nums`.
 */
string intVectorToString(const vector<int> &);

/**
 * Parsing content of an integer vector to string,
 * e.g. "[1,2,3,4,5]"
 *
 * @param nums A vector of integer.
 * @param length Number of elements in vector to parse.
 * @return string of content of `nums`.
 */
string intVectorToString(const vector<int> &, int);

/**
 * Parsing content of a 2d integer vector to string,
 * e.g. "[[1,2,3],[4,5]]"
 *
 * @param values A 2D vector of integer.
 * @return string of content of `values`.
 */
string int2dVectorToString(const vector<vector<int>> &);

/**
 * Parsing content of a 2d integer vector to string,
 * e.g. "[[1,2,3],[4,5]]"
 *
 * @param values A 2D vector of integer.
 * @param pretty boolean for pretty print
 * @return string of content of `values`.
 */
string int2dVectorToString(const vector<vector<int>> &, bool pretty);

/**
 * Parsing content of a 1d char vector to string,
 * e.g. "["a", "b"]"
 *
 * @param s A 1D vector of char.
 * @return string of content of `s`.
 */
string charVectorToString(vector<char> &);

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *intVectorToListNode(vector<int> &);
string listNodeToString(ListNode *);

// Definition of binary tree node
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

template <typename T>
void PrintStack(stack<T> s) {
  // If stack is empty then return
  if (s.empty()) return;

  int x = s.top();

  // Pop the top element of the stack
  s.pop();

  // Recursively call the function PrintStack
  PrintStack(s);

  // Print the stack element starting
  // from the bottom
  cout << x << ", ";

  // Push the same element onto the stack
  // to preserve the order
  s.push(x);
}

#endif
