#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define INF 1e9
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<ll> ans;
multiset<int> lo,hi;
void balance(){
    if(lo.size()-1>hi.size()){
        hi.insert(*prev(lo.end()));
        lo.erase(prev(lo.end()));
    }
    else if(hi.size()>lo.size()){
        lo.insert(*hi.begin());
        hi.erase(hi.begin());
    }
}

vector<int> slidingWindow(vector<int> &arr, int k){
    int n=arr.size();
    for(int i=0;i<n;i++){
        // forming the first window of k elements.
        if(lo.empty() || arr[i]<=*prev(lo.end())) lo.insert(arr[i]);
        else hi.insert(arr[i]);
        balance();
        // we remove the elements if window starts moving forward.
        if(i>=k){
            int out=arr[i-k];
            if(out<=*prev(lo.end())) lo.erase(lo.find(out));
            else hi.erase(hi.find(out));
            balance();
        }
        // 
        if(i>=k-1){
            if(k%2==0){
                ans.pb((*prev(lo.end())+*hi.begin())/2);
            }
            else{
                ans.pb(*prev(lo.end()));
            }
        }
        
    }
}
int main(){

    fast_io;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    slidingWindow(arr, k);
    for(auto &x: ans) cout << x << " ";
    cout << endl;
    return 0;
    
}