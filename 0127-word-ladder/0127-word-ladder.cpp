class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        int ans=1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int qsize=q.size();
            while(qsize--){
                string word=q.front();
                q.pop();
                if(word==endWord)
                    return ans;
                dict.erase(word);
                for(int i=0;i<word.size();i++){
                    char c=word[i];
                    for(int j=0;j<26;j++){
                        word[i]=j+'a';
                        if(dict.find(word)!=dict.end()){
                            q.push(word);
                            dict.erase(word);
                        }
                        word[i]=c;
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};