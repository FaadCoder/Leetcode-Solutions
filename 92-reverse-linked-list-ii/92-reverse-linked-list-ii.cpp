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
        ListNode* reverseBetween(ListNode *head, int left, int right)
        {
            ListNode *dummyNode = new ListNode(0, head);
            ListNode *previousLeft = dummyNode;
            ListNode *curr = head;

            
            // Get the Left Node Position
            for (int itr = 1; itr <= left - 1; itr++)
            {
                previousLeft = curr;
                curr = curr->next;
            }

            // Simply reverse the linked list from startNode to right-left+1 nodes
            ListNode *prev = NULL;

            for (int itr = 1; itr <= right - left + 1; itr++)
            {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            
            // Connect the links
            previousLeft->next->next = curr;
            previousLeft->next = prev;

            return dummyNode->next;
        }
};