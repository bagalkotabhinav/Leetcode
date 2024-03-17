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


    int Length(ListNode* head, int k){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)
            return head;
        
        ListNode* prev=nullptr;
        ListNode* cur=head;
        ListNode* nex=cur->next;
        int count=0;
        int len=Length(head,k);
        if(len<k)
            return head;

        while(count<k){
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
            count++;
        }

        if(nex!=nullptr){
            head->next=reverseKGroup(nex,k);
        }

        return prev;
    }
};