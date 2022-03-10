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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 and !l2)
            return NULL;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *temp,*head;
        int i=0;
        int c=0;
        while(l1 and l2)
        {
            c+=l1->val+l2->val;
            if(i==0)
            {
                temp=new ListNode(c%10);
                head=temp;
                i=1;
            }
            else
            {
                temp->next=new ListNode(c%10);
                temp=temp->next;
            }
            c=c/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            c+=l1->val;
            if(i==0)
            {
                temp=new ListNode(c%10);
                head=temp;
                i=1;
            }
            else
            {
                temp->next=new ListNode(c%10);
                temp=temp->next;
            }
            c=c/10;
            l1=l1->next;
        }
        while(l2)
        {
            c+=l2->val;
            if(i==0)
            {
                temp=new ListNode(c%10);
                head=temp;
                i=1;
            }
            else
            {
                temp->next=new ListNode(c%10);
                temp=temp->next;
            }
            c=c/10;
            l2=l2->next;
        }
        if(c)
        {
            if(i==0)
            {
                temp=new ListNode(c%10);
                head=temp;
                i=1;
            }
            else
            {
                temp->next=new ListNode(c%10);
                temp=temp->next;
            }
            c=c/10;
        }
        return head;
    }
};