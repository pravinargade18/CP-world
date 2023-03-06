class TrieNode{
    public:
        int data;
        TrieNode* children[26];
        bool isTerminal;
        
        TrieNode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};
class Trie {
        TrieNode* root;

public:
    
    Trie() {
        root=new TrieNode('\0');
    }
    
    
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        
        int index=word[0]-'a';
        TrieNode* child;
        
        if(root->children[index]!=NULL){
            // if character is present
            child=root->children[index];
        }
        
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        
        insertUtil(child,word.substr(1));
     }
    void insert(string word) {
        insertUtil(root,word);
    }
    
    
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        
        int index=word[0]-'a';
        TrieNode* child;
        
        if(root->children[index]!=NULL){
            // if character is present
            child=root->children[index];
        }
        
        else{
            // absent
            return false;
        }
        
        return searchUtil(child,word.substr(1));
     }
    
    bool search(string word) {
        return searchUtil(root,word);
    }
   
    
    bool start(TrieNode* root,string word){
        if(word.length()==0){
            return true;
        }
        
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return start(child,word.substr(1));
    }
    
    
    
    bool startsWith(string prefix) {
        return start(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
