/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* deleteMiddle(ListNode *head)
        {
            ListNode *slow = head;
            ListNode *fast = head;
            ListNode *pre = NULL;
            if (!head or!head->next)
                return NULL;

            while (fast and fast->next)
            {
                pre = slow;
                fast = fast->next->next;
                slow = slow->next;
            }

            pre->next = slow->next;
            slow->next = NULL;
            delete(slow);

            return head;
        }
};