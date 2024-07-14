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
    ListNode* sortList(ListNode* head) {
        ListNode* t=head;
        vector<int> num;
        while(t!=NULL){
            num.push_back(t->val);
            t=t->next;
        }
        sort(num.begin(),num.end());
        t=head;
        for(int i=0;i<num.size();i++){
            t->val=num[i];
            t=t->next;
        }
        return head;
    }
};