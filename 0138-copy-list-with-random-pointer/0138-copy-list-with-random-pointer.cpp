/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        ios_base::sync_with_stdio(false); cin.tie(NULL);

        unordered_map<Node*,Node*> mp;

        Node* start= new Node(0);
        Node* cur=start;
        Node* temp=head;
        

        
        while(temp){
            Node* res= new Node(temp->val);
            cur->next=res;
            cur=cur->next;
            mp[temp]=cur;
            temp=temp->next;
            
        }

        temp=start->next;
        cur=head;

        while(temp){
            temp->random=mp[cur->random];
            temp=temp->next;
            cur=cur->next;
        }

        return start->next;
        
    }
};


