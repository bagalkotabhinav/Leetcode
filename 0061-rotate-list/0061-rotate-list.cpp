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
    int count(ListNode* head){
        int count=0;
        ListNode* temp=head;
        if(head==NULL)
            return 0;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        return count+1;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        
        int l=count(head);
        k=k%l;

        for(int i=1;i<=k;i++){
            ListNode* last=NULL;
            ListNode* temp=head;


            while(temp->next!=NULL){
                last=temp;
                temp=temp->next;
            }

            temp->next=head;
            last->next=NULL;
            head=temp;

        }
        return head;
    }
};