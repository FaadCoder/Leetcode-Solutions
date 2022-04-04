/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode *getKthNodeFromStart(ListNode *head, int k)
    {
        auto kthNodeFromstartNode = head;
        for(int move = 1; move<k and kthNodeFromstartNode->next; move++)
            kthNodeFromstartNode = kthNodeFromstartNode->next;
        return kthNodeFromstartNode;
    }
    
    ListNode *getKthNodeFromEnd(ListNode *head, ListNode *kthNodeFromstartNode)
    {
        auto kthNodeFromEnd = head;
        auto temp = kthNodeFromstartNode;
        while(temp->next)
        {
            temp = temp->next;
            kthNodeFromEnd = kthNodeFromEnd->next;
        }
        return kthNodeFromEnd;
    }
    
    
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        if(!head or !head->next)
            return head;
        auto kthNodeFromstartNode = getKthNodeFromStart(head,k);
        auto kthNodeFromEnd = getKthNodeFromEnd(head,kthNodeFromstartNode);
        swap(kthNodeFromstartNode->val,kthNodeFromEnd->val);
        return head;
        
    }
};
