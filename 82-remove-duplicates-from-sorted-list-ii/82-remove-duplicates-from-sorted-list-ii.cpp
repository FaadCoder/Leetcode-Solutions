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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        map<int,int> vis;
        ListNode *ptr = head;
        while(ptr)
        {
            vis[ptr->val]++;
            ptr=ptr->next;
        }
        ptr = head;
        ListNode *prev = ptr;
        bool entered = false;
        for(auto i:vis)
        {
            if(i.second==1)
            {
                ptr->val = i.first;
                prev = ptr;
                ptr=ptr->next;
                entered = true;
            }
        }
        prev->next = NULL;
        if(!entered)
            return NULL;
        return head;
    }
};