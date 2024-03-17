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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //2 POINTER: FAST POINTER N DISTANCE AWAY FROM SLOW POINTER
        //IF FAST IS NULL, IE N IS TOTAL NODES, RETURN HEAD->NEXT
        //ELSE, MOVE TILL FAST->NEXT BECOMES NULL
        //SLOW->NEXT= FAST, BUT IN FEW CASES IT NOT WORK, SO 
        //SLOW->NEXT=SLOW->NEXT->NEXT
        if(head->next==NULL){
            return NULL;
        }
        
        ListNode* fast=head;
        ListNode* slow=head;

        while(n>0){
            fast=fast->next;
            n--;
        }

        if(fast==NULL){
            return head->next;
        }

        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }

        slow->next=slow->next->next;

        return head;
    }
};
