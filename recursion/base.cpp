#include <bits/stdc++.h>
using namespace std;

//Print 1 to N using backtracking and not f(i+1)
void printN(int i,int n){
    if(i<1) return;
    printN(i-1,n);
    cout<<i<<" "; // it wont be executed until all function calls are done
}
// Print all possible subsequence of an array using recursion
void printF(int ind,vector<int> & ds, int arr[],int n){
    if(ind==n){
        for(auto it:ds) cout<<it<<" ";
        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]);
    printF(ind+1,ds,arr,n); // pick
    ds.pop_back();
    printF(ind+1,ds,arr,n); // not pick
    // we can also use the below line instead of the above two lines
    // printF(ind+1,ds,arr,n); // pick
    // ds.push_back(arr[ind]);
    // printF(ind+1,ds,arr,n); // not pick
    // ds.pop_back();
}
// Print the number of possible subsquences having a sum k (here k=2)
int printN(int ind,int arr[],int n,int sum,int s){
    if(s>sum) return 0; // if the sum is greater than the required sum
    //strictly done when array has positive numbers only so once exceeded no need to check further -> reducing complexity 
    if(ind==n){
         if (s==sum) return 1;
         else return 0;
    }
    s+=arr[ind];
    int l=printN(ind+1,arr,n,sum,s); // pick
    s-=arr[ind];
    int r=printN(ind+1,arr,n,sum,s); // not pick
    return l+r;
    // Basic format of this modification of question
}


/* Sorting */

// MERGE SORT
void ms(vector<int> &arr, int low,int high){
    if(low==high) return;
    int mid=(low+high)/2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void merge(vector<int> &arr, int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right =mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
}
// Time complexity of merge sort is O(nlogn) and space complexity is O(n)


// QUICK SORT
int partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j){
        while(arr[i]<=arr[pivot] && i<=high-1) i++;
        while(arr[j]>=arr[pivot] && j>=low+1) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j; // returning the pivot index
}
void qs(vector<int> &arr,int low ,int high){
    if(low < high){
        int pIndex = partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}
vector<int> QuickSort(vector<int> & arr){
    int n=arr.size();
    qs(arr,0,n-1);
    return arr;
}
// Time COmplexity = O(N*logN) and Space Complexity = O(1) , no extra space needed due to recursion stack space





int main(){
    int arr[]= {3,1,2};
    int n=3;
    vector<int> ds;
    printF(0,ds,arr,n);   
}

// Recursion ways -> functional ways or parameter ways