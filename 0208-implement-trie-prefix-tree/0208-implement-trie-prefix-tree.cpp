class Trienode{
public:
    Trienode* children[26];
    bool word;
    Trienode(){
        for(int i=0;i<26;i++)
            children[i]=NULL;
        word=false;
    }
};

class Trie {
public:
    Trienode* root;
    Trie() {
        root=new Trienode();
    }
    
    void insert(string word) {
        Trienode* node=root;
        for(int i=0;i<word.size();i++){
            int ch=word[i]-'a';
            if(node->children[ch]==NULL)
                node->children[ch]=new Trienode();
            node=node->children[ch];
        }
        node->word=true;
    }
    
    bool search(string word) {
        Trienode* node=root;
        for(int i=0;i<word.size();i++){
            int ch=word[i]-'a';
            if(node->children[ch]==NULL)
                return false;
            node=node->children[ch];
        }
        return node->word;
    }
    
    bool startsWith(string word) {
        Trienode* node=root;
        for(int i=0;i<word.size();i++){
            int ch=word[i]-'a';
            if(node->children[ch]==NULL)
                return false;
            node=node->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */