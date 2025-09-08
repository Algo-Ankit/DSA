#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    bool isEnd;
    TrieNode *children[26];
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=nullptr;
    }
};
struct Trie{
  TrieNode *root;
  Trie(){
      root=new TrieNode();
    }

    void insert(int num){
        TrieNode *curr=root;
        for(int bit=31;bit>=0;bit--){
            // extracting bit value
            int bitvalue= (1<<bit)&num;
            if(bitvalue>0) bitvalue=1;

            // inserting in the trie
            if(curr->children[bitvalue]==NULL) curr->children[bitvalue]=new TrieNode();
            curr=curr->children[bitvalue];
        }
        curr->isEnd=true;
    }

    int maxXOR(int num){
        TrieNode *curr=root;
        int maxxor=0;
        for(int bit=31;bit>=0;bit--){
            int bitvalue=(1<<bit)&num;
            if(bitvalue>0) bitvalue=1;

            int oppositeBit=bitvalue^1;
            if(curr->children[oppositeBit]!=NULL){
                if(oppositeBit==1){
                    maxxor |= (1<<bit);
                }
                curr=curr->children[oppositeBit];
            }
            else{
                if(bitvalue==1) maxxor |= (1<<bit);
                curr=curr->children[bitvalue];
            }
        }
        return maxxor^num;
    }
};

int main() {
    
}