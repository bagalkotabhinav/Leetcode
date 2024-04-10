/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<Node*,Node*> mp;
        queue<Node*> q;
        Node* copy=new Node(node->val);
        mp[node]=copy;
        q.push(node);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            for(int i=0;i<temp->neighbors.size();i++){
                Node* neighbor=temp->neighbors[i];
                if(mp.find(neighbor)==mp.end()){
                    mp[neighbor]=new Node(neighbor->val);
                    q.push(neighbor);
                }
                mp[temp]->neighbors.push_back(mp[neighbor]);
            }
        }
        return copy;
    }
};