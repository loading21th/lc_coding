// Source: https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *first, *second;
    int cnt = 0;
    first = second = head;
    while (cnt < k - 1) {
        second = second->next;
        if (!second)
            return NULL;
        cnt++;
    }
    while(second->next != NULL) {
        first = first->next;
        second = second->next;
    }
    return first;
}

