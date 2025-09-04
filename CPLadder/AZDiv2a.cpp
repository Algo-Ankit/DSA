#include <bits/stdc++.h>
using namespace std;

// Q1-> Way too long words
void waytoolongwords(){
    string s; cin>>s;
    char c=s[0];
    int n=s.length();
    if(n>10){
        cout<<c<<n-2<<s[n-1]<<"\n";
    }
    else{
        cout<<s<<"\n";
    }
}
// Q5 ->Desorting
void desorting(){
    int n;cin>>n;
    vector<int> a(n);
    int diff = 1e9;
    bool sorted = true;

    for( int i=0;i<n;i++){
        cin>>a[i];
        if(i>0){
            diff=min(diff,abs(a[i]-a[i-1]));
            if(a[i]<a[i-1]){
                sorted=false;
            }
        }
    }
    if(!sorted) cout<<0<<"\n";
    else cout<< diff/2+1<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        waytoolongwords();
    }
    return 0;

}