//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    bool isPrime(int n) {
        if(n == 1) return false;
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) return false;
        }
        return true; 
    }
    int solve(int Num1,int Num2)
    {   
      //code here
      queue<pair<string, int>> q;
      string s1 = to_string(Num1);
      string s2 = to_string(Num2);
      q.push({s1, 0});
      vector<int> vis(1e5, 0);
      
      while(!q.empty()) {
          string node = q.front().first;
          int step = q.front().second;
          q.pop();
          
          vis[stoi(node)] = 1;
          if(node == s2) return step;
          
          for(int i = 0; i < node.size(); i++) {
              char ch = node[i];
              for(int j = 0; j < 10; j++) {
                  if(i == 0 && j == 0) continue;
                  node[i] = char(j + '0');
                  int n = stoi(node);
                  
                  if(isPrime(n) && !vis[n]) {
                      vis[n] = 1;
                      q.push({node, step + 1});
                  }
              }
              node[i] = ch;
          }
      }
      return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends