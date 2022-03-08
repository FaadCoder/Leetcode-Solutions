/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;
        bool doesCycleExist = false;
        while(slowPtr and fastPtr and fastPtr->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr==fastPtr)
            {
                doesCycleExist = true;
                break;
            }
        }
        return doesCycleExist;
        
    }
};