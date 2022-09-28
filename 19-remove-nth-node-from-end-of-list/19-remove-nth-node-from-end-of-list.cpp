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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = slow;
        
        while(n > 0)
        {
            n -= 1;
            fast = fast->next;
        }
        
        while(fast)
        {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        
        if(slow == head)
            return head->next;
        
        prev->next = slow->next;
        slow->next = NULL;
        
        return head;
    }
};