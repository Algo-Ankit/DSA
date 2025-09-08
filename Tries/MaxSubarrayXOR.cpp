#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    bool isSpecial;
    TrieNode *children[2];
    TrieNode(){
        isSpecial=false;
        for(int i=0;i<2;i++)
            children[i]=NULL;
    }
};
struct Trie{
    TrieNode *root;
    Trie(){
        root=new TrieNode();
    }
    void insert(int num){
        TrieNode *curr=root;
        for(int i=31;i>=0;i--){
            int bitval= (1<<i)&num;
            if(bitval>0) bitval=1;

            if(curr->children[bitval]==NULL) curr->children[bitval]=new TrieNode();
            curr=curr->children[bitval];
        }
        curr->isSpecial=true;
    }

};

int main(){

}