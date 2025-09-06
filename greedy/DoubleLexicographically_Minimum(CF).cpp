#include <bits/stdc++.h>
using namespace std;

int main()
{
	// This code portion does i/o file handling
	#ifndef ONLINE_JUDGE
	// for getting input
	freopen("input.txt","r",stdin);
	// for writing output 
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t-->0){
		string s;
		cin>>s;
		int n=s.size();
		sort(s.begin(),s.end());
		vector<char> ans(n);
		int l=0;
		int r=n-1;
		for (int i=0;i<n;i+=2)
		{
			if(i==n-1) ans[l]=s[i];
			else if(s[i]==s[i+1]){
				ans[l]=s[i];
				ans[r]=s[i]; // s[i] and s[i+1] are equal and same
				l++;
				r--;
			}
			else{
				if (s[i+1]==s[n-1]){
					int k=n-1-i; // calculates the length of the second char
					int firsthalf=ceil(k/2.0);
					int secondhalf=k-firsthalf;
					while(firsthalf-->0){
						ans[l]=s[i+1];
						l++;
					}
					ans[l]=s[i];
					while(secondhalf-->0){
						ans[r]=s[i+1];
						r--;
					}
					break;
				}
				else{
					for(int j=i+1;j<n;j++){
						ans[l]=s[j];
						l++;
					}
					ans[r]=s[i];
					break;
				}
			}
		}
		string answer="";
		for (auto it:ans)
		{
			answer+=it;
		}
		cout<<answer<<endl;
	}
	return 0;

}