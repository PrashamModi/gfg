//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int merge(int low, int mid, int high, int arr[]) {
        int i = low, j = mid + 1;
        vector<int> temp;
        int cnt = 0;
        while(i <= mid && j <= high){
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }else{
                cnt += (mid - i + 1);
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i <= mid) temp.push_back(arr[i++]);
        while(j <= high) temp.push_back(arr[j++]);
        
        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        
        return cnt;
    }
    int mergeSort(int low, int high, int arr[]) {
        if(low >= high) return 0;
        int ans = 0;
        int mid = low + (high - low) / 2;
        ans += mergeSort(low, mid, arr);
        ans += mergeSort(mid + 1, high, arr);
        ans += merge(low, mid, high, arr);
        return ans;
    }
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here 
        for(int i = 0; i < n; i++) {
            arr[i] = (i * arr[i]);
        }
        return mergeSort(0, n - 1, arr);
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends