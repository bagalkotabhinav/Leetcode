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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> st;
        ListNode * head1=headA;
        ListNode * head2=headB;
        while(head1!=nullptr && head2!=nullptr){
            if(head1==head2)
                return head1;
            else if(st.find(head1)!=st.end())
                return head1;
            else if(st.find(head2)!=st.end())
                return head2;
            st.insert(head1);
            st.insert(head2);
            head1=head1->next;
            head2=head2->next;
        }
        while(head1!=nullptr){
            if(st.find(head1)!=st.end())
                return head1;
            st.insert(head1);
            head1=head1->next;
        }
        while(head2!=nullptr){
            if(st.find(head2)!=st.end())
                return head2;
            st.insert(head2);
            head2=head2->next;
        }
        return nullptr;
    }
};