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
    
    ListNode *reverseList(ListNode *start)
    {
        ListNode *curr = start;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    bool areEqual(ListNode *firstPart, ListNode *secondPart)
    {
        ListNode *head1 = firstPart;
        ListNode *head2 = secondPart;
        while(head1 and head2)
        {
            if(head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        
        if(head1 or head2)
            return false;
       return true;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        
        ListNode *sp = head;
        ListNode *fp = head;
        ListNode *prev = head;
        while(fp and fp->next)
        {
            prev = sp;
            sp = sp->next;
            fp = fp->next->next;
        }
        ListNode *firstPart = head;
        ListNode *secondPart = head;
        if(!fp)
        {
            prev->next = NULL;
            secondPart = sp;
        }
        else
        {
            prev->next = NULL;
            secondPart = sp->next;
            sp->next = NULL;
        }
        secondPart = reverseList(secondPart);
        
        return areEqual(firstPart, secondPart);
    }
};

/*

1 2
  s
    f


*/
