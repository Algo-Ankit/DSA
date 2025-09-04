#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define INF 1e9
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<ll> slidingwindowalgo(int n,int k,vector<int> & arr){
    deque<int> dq;
    vector<ll> ans;
    for(int i=0;i<k;i++){
        while(!dq.empty() && arr[dq.back()]>arr[i]) dq.pop_back();
        dq.push_back(i);
    }
    ans.pb(arr[dq.front()]);
    for(int i=k;i<n;i++){
        while(!dq.empty() && arr[dq.back()]>arr[i]) dq.pop_back();
        dq.push_back(i);
        if(dq.front()<=i-k) dq.pop_front();
        ans.pb(arr[dq.front()]);
    }
    return ans;
}

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vector<ll> result = slidingwindowalgo(n, k, arr);
    for(auto &x: result) cout << x << " ";
    cout << endl;
    return 0;

}