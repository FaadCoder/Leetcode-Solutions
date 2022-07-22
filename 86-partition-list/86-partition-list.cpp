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
        
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        ListNode *lessThanX = dummy1;
        ListNode *greaterEqualX = dummy2;
        
        while(head)
        {
            if(head->val<x)
            {
                lessThanX->next = head;
                lessThanX = lessThanX->next;
            }
            else
            {
                greaterEqualX->next = head;
                greaterEqualX = greaterEqualX->next;
            }
            head = head->next;
        }
        greaterEqualX->next = NULL;
        lessThanX->next = dummy2->next;
        return dummy1->next;
        
    }
};