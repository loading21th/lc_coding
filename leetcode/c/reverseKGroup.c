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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(NULL == head || NULL == head->next || k == 1) return head;
        ListNode* father=head;
        ListNode* son=head->next;
        ListNode* gson;
        ListNode *phead=head,*rhead=NULL;
        ListNode* ptail = NULL;
        ListNode** pptail;
        ListNode* kp=head;
        int m = k;
        while(kp){
            m--;
            kp= kp->next;
            if(m==0){
                m = k;
                ptail= father;
                while(son!=kp){
                    gson = son->next;
                    son->next=father;
                    father = son;
                    son=gson;
                }
                phead = father;
                if(NULL == rhead) {
                    rhead = phead;
                }else{
                    *pptail = phead;            
                }
                pptail = &(ptail->next);
                father = kp;
                if(kp){
                    son = father->next;
                }else{
                    break;
                }
                
            }
        }
        if(m>0){
            *pptail = father;
        }else{
            *pptail= NULL;
        }
        if(rhead) return rhead;
        return head;

    }
};


