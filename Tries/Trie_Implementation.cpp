
#include <bits/stdc++.h>

using namespace std;

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

class Trie{
    public:
    TrieNode* root;
    
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        
        int index=word[0]-'A';
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
    
    void insertWord(string word){
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        
        int index=word[0]-'A';
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
    bool searchWord(string word){
        return searchUtil(root,word);
    }
};

int main()
{
    Trie* t=new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout<<"Present or not:"<<t->searchWord("TIM")<<endl;
    return 0;
}
