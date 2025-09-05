#include <bits/stdc++.h>
using namespace std;
#define int long long

int numberoffives(int n){
  int count=0;
  for(int i=5;i<=n;i*=5) count += n/i;
  return count;
}
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;cin>>n;
  if(n%2 != 0) cout<<0<<endl;
  else cout<<numberoffives(n/2)<<endl;
}
