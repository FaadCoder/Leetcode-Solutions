/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    unordered_set<int> hashSet;
    
    void populatePath(Node *node)
    {
        while(node)
        {
            hashSet.insert(node->val);
            node = node->parent;
        }
    }
    
    
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
        populatePath(p);
        while(q)
        {
            if(hashSet.count(q->val))
                return q;
            q = q->parent;
        }
        return NULL;
    }
};