class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        //IDENTIFY WORDS
        vector<string> words;
        string temp="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]!=' ')
                temp+=sentence[i];
            else{
                words.push_back(temp);
                temp="";
            }
        }
        words.push_back(temp);
        
        //COMPARE WORDS WITH DICT AND REPLACE
        for(auto j: dictionary){
            for(int i=0;i<words.size();i++){
                if(words[i].rfind(j,0)==0){
                    words[i]=j;
                }
            }
        }
        
        // APPEND WORDS INTO A SINGLE STRING
        sentence="";
        for(int i=0;i<words.size();i++){
            sentence=sentence+words[i]+' ';
        }
        sentence.pop_back();
        cout<<sentence;

        return sentence;
    }
};