/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<vector<int>> temp;
    void dfs(Node *root, int lvl = 0)
    {
        if(!root)
            return;
        
        if(lvl == temp.size())
            temp.push_back({});
        
        temp[lvl].push_back(root->val);
        
        for(auto child : root->children)
        {
            dfs(child, lvl + 1);
        }
    }
    
public:
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root);
        return temp;
    }
};