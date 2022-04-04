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
        ListNode *kthNodeFromstartNode = head;
        for(int move = 1; move<k and kthNodeFromstartNode->next; move++)
            kthNodeFromstartNode = kthNodeFromstartNode->next;
        return kthNodeFromstartNode;
    }
    
    ListNode *getKthNodeFromEnd(ListNode *head, ListNode *kthNodeFromstartNode)
    {
        ListNode *kthNodeFromEnd = head;
        ListNode *temp = kthNodeFromstartNode;
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
        
        // Algorithm: 
        // Step 1: Get Kth Node From Start.
        ListNode *kthNodeFromstartNode = getKthNodeFromStart(head,k);
        // Step 2: Get Kth Node From End.
        ListNode *kthNodeFromEnd = getKthNodeFromEnd(head,kthNodeFromstartNode);
        // Step 3: Swap their Values.
        swap(kthNodeFromstartNode->val,kthNodeFromEnd->val);
        
        return head;
        
    }
};
