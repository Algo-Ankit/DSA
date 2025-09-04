#include <bits/stdc++.h>
using namespace std;


// Factory Machines -> CSES TLE sheet
bool checktime(long long mid,vector<long long> &a,long long t,int n){
    long long noproducts=0;
    for(int i=0;i<n;i++){
        noproducts+=mid/a[i];
        if(noproducts >= t)  return true;
    }
    return noproducts>=t;
}

void factoryMachines(){
    long long n,t;
    cin >> n >> t;
    vector<long long> time(n);
    for(int i=0;i<n;i++) cin >> time[i];
    long long low=0,high=1e18;
    long long ans=high;
    while (low<=high){
        long long mid=(low+high)/2;
        if(checktime(mid,time,t,n)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout << ans << endl;  
}





// Array Division Problem -> CSES TLE sheet
bool checkarray(long long targetSum, const vector<long long> &a, int n, int k)
{   
    int noofsubarray = 1;
    long long cursum = 0;
    for (int i = 0; i < n; i++)
    {
        if (cursum + a[i] > targetSum)
        {
            noofsubarray++;
            cursum = 0;
        }
        cursum += a[i];
    }
    return noofsubarray <= k;
}
void ArraydivisionCSES()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long low = 0, high = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        low = max(low, a[i]);
        high += a[i];
    }

    long long ans = high;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (checkarray(mid, a, n, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}

// Main function
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    factoryMachines();
    return 0;
}
