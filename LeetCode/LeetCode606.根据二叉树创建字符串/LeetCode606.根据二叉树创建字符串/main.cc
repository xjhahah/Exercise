#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  string tree2str(TreeNode* t) {
    if (t == nullptr) return "";
    stringstream ss;
    function<void(TreeNode*)> helper = [&ss, &helper](TreeNode* t) {
      ss << t->val;
      if (t->left == nullptr) {
        if (t->right != nullptr) {
          ss << "()(";
          helper(t->right);
          ss << ')';
        }
      } else if (t->right == nullptr) {
        ss << '(';
        helper(t->left);
        ss << ')';
      } else {
        ss << '(';
        helper(t->left);
        ss << ")(";
        helper(t->right);
        ss << ')';
      }
    };
    helper(t);
    string s;
    ss >> s;
    return s;
  }
};