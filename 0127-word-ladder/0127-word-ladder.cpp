class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ans=1;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                string temp=q.front();
                q.pop();
                if(temp==endWord)
                    return ans;
                for(int i=0;i<temp.size();i++){
                    char c=temp[i];
                    for(int j=0;j<26;j++){
                        temp[i]=j+'a';
                        if(dict.find(temp)!=dict.end()){
                            q.push(temp);
                            dict.erase(temp);
                        }
                    }
                    temp[i]=c;
                }
            }
            ans++;
        }
        return 0;
    }
};