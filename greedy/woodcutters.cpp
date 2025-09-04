#include <bits/stdc++.h>
using namespace	std;

//All Macros
typedef vector<pair<int, int>> vpi;
#define all(x) (x).begin(), (x).end()


int main(){
	int n;cin>>n;
	vpi v(n);
	for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
	sort(all(v));
	
	int ans=1;
	for(int i=1;i<n;i++){
		if(abs(v[i].first-v[i-1].first)>v[i].second) ans++;
		else{
			if(i==n-1){
				ans++;
			}
			else if(abs(v[i].first-v[i+1].first)>v[i].second){
				ans++;
				v[i].first += v[i].second;
			}
		}
	}
	cout<<ans<<endl;

}