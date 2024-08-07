//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n1=(int)arr1.size();
        int n2=(int )arr2.size();
        
        int n=n1+n2;
        
        int low=max(0,k-n2);
        int high=min(n1,k);
        int left=k;
        
         while(low<=high)
        {
            int mid1=(low+high)/2;
            
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            int mid2=(left-mid1);
            if(mid1<n1)
            {
                r1=arr1[mid1];
            }
            if(mid2<n2)
            {
                r2=arr2[mid2];
            }
            if(mid1>=1)
            {
                l1=arr1[mid1-1];
            }
            if(mid2>=1)
            {
                l2=arr2[mid2-1];
            }
            
            if(l1>r2)
            {
                high=mid1-1;
            }
            else if(l2>r1)
            {
                low=mid1+1;
            }
            else
            {
                return max(l1,l2);
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends