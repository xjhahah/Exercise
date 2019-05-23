#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x)
    :val(x)
     ,left(nullptr)
     ,right(nullptr)
  {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {     
      //解法二：利用前序遍历思想，只不过将根左右写成根右左，然后再逆置vector就是我们想要的结果，想法很巧妙
      vector<int> v;
      stack<TreeNode*> s;
      TreeNode* cur=root;
      while(!s.empty() || cur!=nullptr){
        if(cur!=nullptr){
          v.push_back(cur->val);
          s.push(cur);
          cur=cur->right;
        }
        else{
          TreeNode* node = s.top();
          s.pop();
          cur=node->left;
        }
      }
      vector<int> vv(v.rbegin(),v.rend());
      return vv;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<int> ret = Solution().postorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
