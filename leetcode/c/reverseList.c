// Source: https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev, *next, *cur;
    if (head == NULL)
        return NULL;
    prev = NULL;
    cur  = head;
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

