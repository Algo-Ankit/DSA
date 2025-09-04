#include <bits/stdc++.h>  
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define INF 1e9
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
struct trieNode{
    trieNode *children[2];
    bool isEnd;
    trieNode(){
        isEnd = false;
        for(int i = 0; i < 2; i++)children[i] = NULL;
    }
};

// Implementing Biary Tries to find maximum XOR pair in an array and we input the quesries and conditions 
// Solution ot a GFG Question: https://www.geeksforgeeks.org/problems/maximum-xor-with-an-element-from-array/1

class Trie{
    trieNode *root;
public:
    Trie(){
        root = new trieNode();
    }
    void insert(int num){
        trieNode *curr= root;
        for(int bit=31;bit>=0;bit--){
            int bitval =(1<<bit)&num;
            if(bitval >0) bitval=1;
            if(curr->children[bitval]==NULL) curr->children[bitval]=new trieNode();
            curr = curr->children[bitval];
        }
        curr->isEnd = true;
    }
    int maxXORpair(int num){
        trieNode *curr=root;
        int maxxor=0;
        for(int bit=31;bit>=0;bit--){
            int bitval=(1<<bit)& num;
            if(bitval>0) bitval=1;
            int oppbitval=bitval^1;
            if(curr->children[oppbitval]!=NULL){
                if(oppbitval==1) maxxor= maxxor | (1<<bit);
                curr = curr->children[oppbitval];
            }
            else{
                if(bitval==1) maxxor= maxxor | (1<<bit);
                curr = curr->children[bitval];
            }
        }
        return maxxor^num;
    }

};

vector<ll> maxXOR(int n,int q,vector<int> & arr,vector<vector<int>> & queries){
    sort(all(arr));
    vector<pair<ll,pair<ll,ll>>> oq;
    for(int i=0;i<q;i++)
        oq.pb({queries[i][1],{queries[i][0],i}});
    sort(all(oq));
    
    vector<ll> ans(q,0);
    Trie *t= new Trie();
    ll index=0;
    for(int i=0;i<q;i++){
        ll mi= oq[i].first;
        ll xi= oq[i].second.first;
        ll qind= oq[i].second.second;
        while(index<n && arr[index]<=mi){
            t->insert(arr[index]);
            index++;
        }
        if(index!=0)
            ans[qind]=t->maxXORpair(xi);
        else ans[qind]=0;
    }
    return ans;
}

int main(){
    fast_io;
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }
    
    vector<ll> result = maxXOR(n, q, arr, queries);
    
    for (ll res : result) {
        cout << res << "\n";
    }
    
    return 0;
}