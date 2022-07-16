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

class Solution
{
    public:
        Node* findRoot(vector<Node*> tree)
        {
            if (tree.empty())
                return NULL;
            int nodeAppearOnce = 0;
            for (auto treeNode: tree)
            {
                nodeAppearOnce ^= treeNode->val;
                for (auto child: treeNode->children)
                {
                    nodeAppearOnce ^= child->val;
                }
            }

            for (auto treeNode: tree)
                if (nodeAppearOnce == treeNode->val)
                    return treeNode;

            return NULL;
        }
};