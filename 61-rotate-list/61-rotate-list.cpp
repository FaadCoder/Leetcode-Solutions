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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next)
    return head;
    int cnt=0;
    auto temp=head;
    while(temp)
    {
        cnt++;
        temp=temp->next;
    }
    if(cnt==1 or k==0 or cnt==k)
        return head;
    k%=cnt;
    if(k==0)
        return head;
    auto prev=head;
    temp=head;
    for(int i=1;i<=cnt-k;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    auto check=temp;
    prev->next=NULL;
    while(temp->next)
    temp=temp->next;
    temp->next=head;
    return check;
    }
};