#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void moneyTrees(){
      int t;
    cin>>t;
    while(t-->0){
        int n,k;cin>>n>>k;
        vector<int> a(n);
        vector<int> h(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>h[i];
        vector<int> pre(n);
        for(int i=0;i<n-1;i++){
            if(h[i]%h[i+1]==0) pre[i]=1;
            else pre[i]=0;
        }
        int l=0,r=0;
        int ans=1;
        int cnt=0;

        if(k < *min_element(a.begin(),a.end())) cout<<0<<endl;

        vector<int> prefix(n);
        prefix[0]=a[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+a[i];

        while(r<n-1){
            if(pre[r]==0){
                cnt=0;
                r++;
                l=r;
                continue;
                //i.e. we start a new window from next element as we cant start from 0
            }
            cnt+=a[r];
            while(l<=r && cnt>k){
                cnt -= a[l];
                l++;
            }
            if(cnt+a[r+1]<=k) ans=max(ans,r-l+2);
            else ans=max(ans,r-l+1);
            l++;
        }
        cout<<ans<<endl;

    }
}

void loopedPlaylist(){
    ll n,p;
    cin>>n>>p;
    vector<int> a(n);
    ll sumtotal=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sumtotal+=a[i];
    }
    ll temp=0;
    if(sumtotal<p){
        temp += p/sumtotal; // to know how many times we will traverse the array
        p = p%sumtotal; // new value of p to be achieved
    }
    int start=-1;
    int cnt=INT_MAX;
    // now to get positivity value of leftover p -> we eun a for loop to decide the start element
    for(int i=0;i<n;i++){
        ll sum=0;
        int j=i; //-> index j denotes current element where we are
        int taken=0; //-> denotes the number of songs heard starting from ith element (initially 0);
        while(sum < p){
            sum+=a[j]; //->add the next value to sum as it didnt reached the positivity value
            taken++;//-> increase taken as we heard an additional song
            j=(j+1)%n; // to scale the j to range on 1 to n ( for 0 1 2 3 4 and after 4 comes 0 then (4+1)=5%4=0 index of next element without overflowing)
        }
        if(taken>cnt){
            cnt=taken;
            start=i;
        }
    }
    

}
int main(){
  
}