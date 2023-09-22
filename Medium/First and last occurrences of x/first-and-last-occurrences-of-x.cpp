//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int firstOccurrence = -1; // Initialize the first occurrence index to -1.
        int lastOccurrence = -1; // Initialize the last occurrence index to -1.
    
        // Binary search for the first occurrence of x.
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                firstOccurrence = mid;
                high = mid - 1; // Continue searching on the left side.
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        // Binary search for the last occurrence of x.
        low = 0;
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                lastOccurrence = mid;
                low = mid + 1; // Continue searching on the right side.
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        // Create a vector to store the result.
        vector<int> result;
        result.push_back(firstOccurrence);
        result.push_back(lastOccurrence);
    
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends