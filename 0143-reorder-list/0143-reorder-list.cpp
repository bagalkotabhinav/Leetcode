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
    void reorderList(ListNode* head) {

        if(head==NULL || head->next==NULL) return;
        
        //REVERSAL
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=slow->next;
        slow->next=NULL;

        ListNode* cur=head2;
        ListNode* prev=NULL;

        while(cur!=NULL){
            ListNode* nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        head2=prev;

        //REORDERING
        ListNode* first=head;
        ListNode* temp=head;
        ListNode* second=head2;

        while(temp->next!=NULL && second->next!=NULL){
            temp=first->next;
            first->next=second;
            second=second->next;
            first->next->next=temp;
            first=temp;
        }
        temp=temp->next;
        first->next=second;
        second->next=temp;
    }
};

//EVEN:
//Reverse linked list after half
//last node in first half, next=NULL
//1.first connect to 2.first
//2.first connect to 1.second
//1.first=1.first->next
//2.first=2.first->next

//ODD:
//Reverse linked list after half; keep the middle node in first half
//last node in first half=NULL
//1.first connect to 2.first
//2.first connect to 1.second
//1.first=1.first->next
//2.first=2.first->next