class Solution {
public:
    bool tree(vector<int>& parent, vector<int>& rank, int n1, int n2){
        int p1=find_parent(parent,n1);
        int p2=find_parent(parent,n2);
        if(p1==p2)
            return false;
        if(rank[p1]>=rank[p2]){
            parent[p2]=p1;
            rank[p1]+=rank[p2];
        }
        else{
            parent[p1]=p2;
            rank[p2]+=rank[p1];
        }
        return true;
    }
    int find_parent(vector<int>& parent, int n){
        int curnode=n;
        int pnode=parent[n];
        while(curnode!=pnode){
            int anode=parent[pnode];
            curnode=pnode;
            pnode=anode;
        }
        return curnode;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1);
        vector<int> rank(edges.size()+1,1);
        for(int i=1;i<=edges.size();i++)
            parent[i]=i;
        for(auto i: edges){
            int n1=i[0];
            int n2=i[1];
            if(tree(parent,rank,n1,n2)==false)
                return {n1,n2};
        }
        return {};
    }
};