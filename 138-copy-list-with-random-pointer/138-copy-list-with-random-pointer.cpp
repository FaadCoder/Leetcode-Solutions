/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        // Base Case: 
        if(!head)
            return NULL;
        //  Step 1: create copy nodes after every node
        Node *l1=head;
        while(l1!=NULL)
        {
            Node *node = new Node(l1->val);
            node->next = l1->next;
            l1->next = node;
            l1=node->next;
        }
        // Step 2: Connect Random Pointers
        l1=head;
        while(l1!=NULL)
        {
            if(l1->random)
                l1->next->random = l1->random->next;
            l1=l1->next->next;
        }
        // Step 3:
        Node *copyHead = head->next;
        Node *l2=copyHead;
        l1=head;
        while(l1)
        {
            l1->next = l2->next;
            if(l2->next)
            l2->next = l2->next->next;
            l1=l1->next;
            l2=l2->next;
        }
        return copyHead;
    }
};