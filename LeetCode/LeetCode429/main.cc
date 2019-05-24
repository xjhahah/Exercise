#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int size=q.size();
            while(size--){
                Node* tmp=q.front();
                q.pop();
                v.push_back(tmp->val);
                vector<Node*> child=tmp->children;
                for(const auto& e : child){
                    q.push(e);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};

int main()
{
	return 0;
}
