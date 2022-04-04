# Algorithm:
1) ***Get Kth Node From Start.***
* ListNode *kthNodeFromstartNode = getKthNodeFromStart(head,k);
2) **Get Kth Node From End.**
* ListNode *kthNodeFromEnd = getKthNodeFromEnd(head,kthNodeFromstartNode);
3) **Swap their Values.**
* swap(kthNodeFromstartNode->val,kthNodeFromEnd->val);