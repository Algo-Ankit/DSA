#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct TrieNode{
    public:
    int strings_below;
    int strings_end;
    TrieNode *children[26];
    TrieNode(){
        strings_below=0;
        strings_end=0;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};

class trie{
  public:
  TrieNode *root;
  trie(){
    root=new TrieNode();
  }
  void insert(string s){
    TrieNode *curr=root;
    for(auto ch:s){
        if(curr-> children[ch-'a']==NULL){
            curr->children[ch-'a']=new TrieNode();
        }
        curr=curr->children[ch-'a'];
        curr->strings_below++;
    }
    curr->strings_end++;
  }
  bool search(string s){
    TrieNode *curr=root;
    for(auto ch:s){
        if(curr->children[ch-'a']==NULL){
            return false;
        }
        curr=curr->children[ch-'a'];
    }
  }

  // Delete in pointer based approach is not viable as it can lead to memory leaks
  // and dangling pointers. Instead, we can use a reference counting mechanism
  // to keep track of the number of strings that are still using a particular node.
  // This way, we can safely delete nodes when they are no longer needed.
};