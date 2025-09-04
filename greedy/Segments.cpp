#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool compare(pair<ll,ll>a,pair<ll,ll> b){
	if(a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;cin>>n;
	vector<pair<int ,int >> v(n);
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		v[i].first=min(a,b);
		v[i].second=max(a,b);
	}
	sort(v.begin(),v.end(),compare);

	int nail=v[0].second;
	vector<int> nv;
	nv.push_back(nail);

	for(auto [l,r]:v){
		if(l>nail){
			nail=r;
			nv.push_back(nail);
		}
	}
	cout<<nv.size()<<'\n';
	for(int i=0;i<nv.size();i++) cout<<nv[i]<<' ';
}