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
    
    ListNode *getReverseList(ListNode *start)
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
    
    bool areEqual(ListNode *firstHalf, ListNode *secondHalf)
    {
        ListNode *head1 = firstHalf;
        ListNode *head2 = secondHalf;
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
    
    ListNode *getSecondHalf(ListNode *head)
    {
        
        ListNode *sp = head;
        ListNode *fp = head;
        ListNode *prev = head;
        ListNode *secondPart = head;
        
        while(fp and fp->next)
        {
            prev = sp;
            sp = sp->next;
            fp = fp->next->next;
        }
        
        prev->next = NULL;
        
        if(!fp)
        {
            secondPart = sp;
        }
        else
        {
            secondPart = sp->next;
            sp->next = NULL;
        }
        return secondPart;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        
        ListNode *firstHalf = head;
        ListNode *secondHalf = getSecondHalf(head);
        
        secondHalf = getReverseList(secondHalf);
        
        return areEqual(firstHalf, secondHalf);
    }
};

