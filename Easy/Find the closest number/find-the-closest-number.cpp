//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int it = lower_bound(arr, arr + n, k) - arr;
        if(arr[it] == k) {
            return k;
        }
        else if(it == 0) {
            arr[0];
        }
        int minDiff = k - arr[it - 1];
        int maxDiff = arr[it] - k;
        if(minDiff >= maxDiff) {
            return arr[it];
        }
        return arr[it - 1];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends