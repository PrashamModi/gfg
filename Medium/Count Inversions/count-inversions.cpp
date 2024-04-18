//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long low, long long mid, long long high, long long arr[]) {
        vector<long long> temp;
        long long i = low, j = mid + 1;
        long long cnt = 0;
        while(i <= mid && j <= high) {
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
        
        for(long long k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
        return cnt;
    }
    long long mergeSort(long long low, long long high, long long arr[]) {
        if(low >= high) return 0;
        long long cnt = 0;
        int mid = low + (high - low) / 2;
        cnt += mergeSort(low, mid, arr);
        cnt += mergeSort(mid + 1, high, arr);
        cnt += merge(low, mid, high, arr);
        return cnt;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        return mergeSort(0, n - 1, arr);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends