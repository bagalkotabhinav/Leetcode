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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);


        priority_queue <int, vector<int>, greater<int> > pq; 

        ListNode* start=new ListNode();
        ListNode* temp=start;
        int n=lists.size();

        for(int i=0;i<n;i++){
            ListNode* cur=lists[i];
            while(cur!=nullptr){
                pq.push(cur->val);
                cur=cur->next;
            }
        }

        while(!pq.empty()){
            int mini=pq.top();
            pq.pop();
            ListNode* cur=new ListNode(mini);
            temp->next=cur;
            temp=temp->next;
        }
        return start->next;
    }
};