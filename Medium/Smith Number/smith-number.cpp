//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool isPrime(int n) {
        if(n == 1) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    int f1(int n) {
        int res = 0;
        while(n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    int f2(int n) {
        int sum = 0;
        int i = 1;
        while(n > 1) {
            i++;
            if(!isPrime(i)) continue;
            while(n % i == 0) {
                sum += f1(i);
                n /= i;
            }
        }
        return sum;
    }
    int smithNum(int n) {
        // code here
        if(isPrime(n)) return 0;
        int sum1 = f1(n);
        int sum2 = f2(n);
        return sum1 == sum2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends