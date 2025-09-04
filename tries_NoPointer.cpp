#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// No Pointer Based Approach
struct TrieNode
{
    vector<int> children;
    int string_end_here;
    int string_going_below;
    TrieNode(){
        children.resize(26,-1);
        string_end_here = 0;
        string_going_below = 0;
    }

};

struct tries
{
    vector<TrieNode> TrieTree;
    int size=0;
    tries(){
        TrieTree.push_back(TrieNode()); // root node
        size++;
    }
    void insert(string s){
        int curNode=0;
        for(char ch:s){
            int index=ch-'a';
            if(TrieTree[curNode].children[index]==-1){
                TrieTree[curNode].children[index]=size;
                TrieTree.push_back(TrieNode());
                size++;
            }
            curNode=TrieTree[curNode].children[index]; // Moves To Next Node
            TrieTree[curNode].string_going_below++; 
        }
        TrieTree[curNode].string_end_here++;
    }
    bool search(string s){
        int curNode=0;
        for(auto ch:s){
            int index=ch-'a';
            if(TrieTree[curNode].children[index]==-1){
                return false;
            }
            curNode=TrieTree[curNode].children[index];
        }
    }
    void deletestring(string s){
        if (search(s)==false) return;
        int curNode=0;
        for(auto ch:s){
            int index=ch-'a';
            int child=TrieTree[curNode].children[index];
            TrieTree[curNode].string_going_below--;
            if(TrieTree[child].string_going_below==0){
                TrieTree[curNode].children[index]=-1;
                return;
            }
            curNode=child;
        }
        TrieTree[curNode].string_end_here--;
    }
};
