#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
vector<ll> a(n);
vector<ll> b(m);
bool checker(ll r,const vector<ll>& a, const vector<ll>& b){
	int i=0,j=0;

	while(i<a.size() && j<b.size()){
		if(abs(a[i]-b[j])<=r){
			i++;
		}else{
			j++;
		}
	}
	return i == a.size();
}
int main(){
	cin>>n>>m;
	a.resize(n);
	b.resize(m);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];

	ll l=0,r=2e9;
	ll ans=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(checker(mid,a,b)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans<<endl;
}