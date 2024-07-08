//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findPivatIndex(vector<int>&arr,int key){
        int s=0, e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]>arr[mid+1])return mid;
            if(arr[mid-1]>arr[mid])return mid-1;
            if(arr[0]<=arr[mid])s=mid+1;
            else e=mid-1;
        }
        return -1;
    }
    int binarySearch(int s,int e,vector<int>&arr,int key){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==key)return mid;
            if(arr[mid]<key)s=mid+1;
            else e=mid-1;
        }
        return -1;
    }
    int search(vector<int>& arr, int key) {
        int pivotidx=findPivatIndex(arr,key);
        if(key>=arr[0]&&key<=arr[pivotidx]){
            return binarySearch(0,pivotidx,arr,key);
        }
        return binarySearch(pivotidx+1,arr.size()-1,arr,key);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends