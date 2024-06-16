//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    vector<int> getPrimes(int n) {
        // to find all prime numbers in O(nlog(logn))
        vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        
        for(int p = 2; p <= sqrt(n); p++){
            if(is_prime[p]){
                for(int i = p*p; i <= n; i += p){
                    is_prime[i] = false;
                }
            }
        }
        
        
        // using two-pointer to find pair that is equal to sum
        int i = 2;
        int j = n;
        while(!is_prime[j])j--;
        
        while(i <= j){
            int sum = i + j;
            if(sum == n) return {i, j};
            else if (sum > n){
                j--;
                while(!is_prime[j]) j--;
            }
            else{
                i++;
                while(!is_prime[i]) i++;
            }
        }
        
        return {-1, -1};
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends