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
    
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
       Node *a = p, *b = q;
        while(a!=b)
        {
            a = (a)?a->parent:q;
            b = (b)?b->parent:p;
        }
        return a;
    }
};