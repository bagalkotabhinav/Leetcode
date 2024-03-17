/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);


        ListNode* ans= new ListNode(0);
        ListNode* temp=ans;
        int carry=0;

        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int d1=(l1!=nullptr)?l1->val:0;
            int d2=(l2!=nullptr)?l2->val:0;

            int num=d1+d2+carry;

            ListNode* res= new ListNode(num%10);
            carry=num/10;

            temp->next=res;
            l1=(l1!=nullptr)?l1->next:nullptr;
            l2=(l2!=nullptr)?l2->next:nullptr;
            temp=res;
        }

        ListNode* res=ans->next;

        delete ans;

        return res;
        

        
    }
};

// add 1st num and 2nd num and carry as num
//store num/10 in a node
//keep num%10 as carry
//continue till all nodes are done

//create new list as ans with value 0;
// while l1 and l2 not nullptr, compute and store
//if any one nullptr, do separate while loop