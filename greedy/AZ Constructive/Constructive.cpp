#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*---------------------
Ingenuity-2 CF(D)->1400
-----------------------*/
void ingenuity() {
	int n; cin >> n;
	string s; cin >> s;

	if (n == 1) {
		cout << "NO\n";
		return;
	}

	int N = 0, S = 0, E = 0, W = 0;
	for (char c : s) {
		if (c == 'N') N++;
		if (c == 'S') S++;
		if (c == 'E') E++;
		if (c == 'W') W++;
	}

	// Final positions same if total vector is zero
	if (N != S || E != W) {
		cout << "NO\n";
		return;
	}

	// Safe to split — assign alternating instructions
	string ans = s;
	bool usedR = false, usedH = false;

	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			ans[i] = 'R';
			usedR = true;
		} else {
			ans[i] = 'H';
			usedH = true;
		}
	}

	if (usedR && usedH)
		cout << ans << '\n';
	else
		cout << "NO\n";
}

/*-------------------
FLipper CF(D) 1400
---------------------*/
void flipper(){
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];

	int r=0;
	for(int i=0;i<n;i++){
		if(v[min(n-1,r+1)]<=v[min(n-1,i+1)]) r=i;
	}
	int l=r;
	while(l>0 && v[l-1]>v[0]) l--;

	vector<int> ans;
	for(int i=r+1;i<n;i++) ans.push_back(v[i]);
	for(int i=r;i>=l;i--) ans.push_back(v[i]);
	for(int i=0;i<l;i++) ans.push_back(v[i]);

	for(int a:ans) cout<<a<<" ";
	cout << "\n";

}



/*--------------
ABBC or BACB -> 1500 CF(G)
----------------*/
void abbc()
{
	string s;
	cin >> s;
	int n = s.size();
	// count A and collect them
	int totalA = 0;
	vector<int> group;
	int run=0;
	for(char c:s){
		if(c=='A'){
			totalA++;
			run++;
		}else if(run>0){
			group.push_back(run);
			run = 0;
		}
	}
	if(run>0){
		group.push_back(run);
	}// for the last run of A's

	//If string starts with B, ends with B, or has "BB" anywhere,
	//    then B's can sweep and eat every A.
	bool eat=false;
	if(s.front()=='B' || s.back()=='B') eat=true;
	for(int i=0; i < n - 1; i++)	if(s[i]=='B' && s[i+1]=='B') eat=true;

	if(eat) cout<<totalA<<endl;
	else{
		if (group.empty()) {
            cout << 0 << "\n";
        } else {
            // Leave the smallest A-run uneaten
            int smallest = *min_element(group.begin(), group.end());
            cout << (totalA - smallest) << "\n";
        }
	}
	
	
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        flipper();
    }
    return 0;
}