#include <bits/stdc++.h>
using namespace std;
// Kadane's Algorithm Template
// kadanes algo is mainly used for finding the maximum sum subarray in an array
// it can also be used to find the minimum sum subarray by inverting the sign of all elements in the array

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int kadaneSum=0;
    int maxSum=INT_MIN; // for all negative elements case
    int ans=0; // ans as the max sum of subarray
    for(int i=0;i<n;i++){
        kadaneSum += arr[i];
        maxSum = max(maxSum,kadaneSum); // update maxSum if kadaneSum is greater
        if(kadaneSum>0) ans=max(ans,kadaneSum);
        else kadaneSum=0; // reset kadaneSum if it becomes negative
    }
    cout<<ans<<endl;
    return 0;
}