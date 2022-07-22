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
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        ListNode *lessThanXHead = NULL,*greaterThanEqualXHead = NULL;
        ListNode *lessThanXTail = NULL, *greaterThanEqualXTail = NULL;
        ListNode *curr = head;
        
        while(curr)
        {
            ListNode *temp = new ListNode(curr->val); 
            if(curr->val<x)
            {
                if(!lessThanXHead)
                {
                    lessThanXHead = temp;
                    lessThanXTail = temp;
                }
                else
                {
                    lessThanXTail->next = temp;
                    lessThanXTail = lessThanXTail->next;
                }
            }
            else
            {
                if(!greaterThanEqualXHead)
                {
                    greaterThanEqualXHead = temp;
                    greaterThanEqualXTail = temp;
                }
                else
                {
                    greaterThanEqualXTail->next = temp;
                    greaterThanEqualXTail = greaterThanEqualXTail->next;
                }
            }
            curr=curr->next;
        }
        
        if(!lessThanXHead)
            return greaterThanEqualXHead;
        if(!greaterThanEqualXHead)
            return lessThanXHead;
        
        lessThanXTail->next = greaterThanEqualXHead;
        return lessThanXHead;
    }
};