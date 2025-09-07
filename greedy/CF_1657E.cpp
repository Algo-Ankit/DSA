#include <bits/stdc++.h>
using namespace std;

//Q> 1657-E Replace with Previous , minimize.
int main(){
    int t;cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;

        string s;cin>>s;
        char maxpossible='a';
        char notpossible='a';

        for(int i=0;i<n;i++){
            if(s[i]-'a'>k){
                notpossible=s[i];
                break;
            }
            if(s[i]>maxpossible){
                maxpossible=s[i];
            }
        }

        int operationcount=maxpossible-'a';
        int leftoperations=k-operationcount;
        char to = notpossible-leftoperations; // the char we can convert to -> the not possible char with left operations
        for(char c=notpossible;c>to;c--){
            for(char &ch:s){
                if(ch==c) ch--;
            }
        }
        for(char &st:s){
            if(st<=maxpossible) st='a';
        }

        
        cout<<s<<endl;
    }
    return 0;
}