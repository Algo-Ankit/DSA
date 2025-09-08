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
            int bitval=(1<<i)&num;
            if(bitval>0) bitval=1;
            
            if(curr->children[bitval]==NULL) curr->children[bitval]=new TrieNode();
            curr=curr->children[bitval];
        }
        curr->isSpecial=true;
    }
    int maximumXOR(int num){
        TrieNode *curr=root;
        int maxxor=0;
        for(int bit=31;bit>=0;bit--){
            int bitval=(1<<bit)&num;
            if(bitval>0) bitval=1;
            
            int oppbitval=bitval^1;
            
            if(curr->children[oppbitval]!=NULL){
                if(oppbitval==1) maxxor |= (1<<bit);
                curr=curr->children[oppbitval];
            }
            else{
                if(bitval==1) maxxor |= (1<<bit);
                curr=curr->children[bitval];
            }
        }
        return maxxor^num;
    }
};

int maxSubarrayXOR(int N, int arr[]) {
        // code here
        Trie *t=new Trie();
        t->insert(0);
        int num=arr[0];
        t->insert(num);
        int ans=0;
        ans=max(ans,t->maximumXOR(num));
        
        for(int i=1;i<N;i++){
            num = num^arr[i];
            t->insert(num);
            ans=max(ans,t->maximumXOR(num));
        }
        return ans;
    }
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<maxSubarrayXOR(n,arr);
}