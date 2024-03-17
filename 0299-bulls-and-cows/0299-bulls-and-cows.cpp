class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map <int,int> key;
        string ans="";
        int bulls=0,cows=0;
        for(int i=0;i<guess.size();i++){
            key[secret[i]]++;;
        }

        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
        }

        for(int i=0;i<secret.size();i++){
            if(key.find(guess[i])!=key.end()){
                cows++;
                key[guess[i]]--;
                if(key[guess[i]]==0){
                    key.erase(guess[i]);
                }
            }
        }
        cows=cows-bulls;
        ans+=to_string(bulls);
        ans+='A';
        ans+=to_string(cows);
        ans+='B';

        return ans;
    }
};