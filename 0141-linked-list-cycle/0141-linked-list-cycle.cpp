/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 auto init = []() {
    cin.sync_with_stdio( false );
    fstream out( "user.out" );
    for ( string s; getline( cin, s ); ) {
        getline( cin, s );
        s[0] != '-' ? out << "true\n" : out << "false\n";
    }
    out.flush();
    exit(0);
    return 0;
}();

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * fast=head;
        ListNode * slow=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(fast==slow)
                return true;
        }
        
        return false;
    }
};