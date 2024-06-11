//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        if(a.first != b.first) return a.first >= b.first;
        return a.second < b.second;
    }
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {abs(arr[i] - brr[i]), i};
        }
        sort(v.begin(), v.end(), cmp);
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            if(x == 0) {
                sum += brr[v[i].second];
                y--;
            }
            else if(y == 0) {
                sum += arr[v[i].second];
                x--;
            }
            else{
                if(arr[v[i].second] >= brr[v[i].second]) {
                    sum += arr[v[i].second];
                    x--;
                }else{
                    sum += brr[v[i].second];
                    y--;
                }
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends