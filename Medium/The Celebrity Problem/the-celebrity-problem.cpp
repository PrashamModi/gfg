//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& v, int n) 
    {
        // code here 
        stack<int> s;
        for(int i = 0; i < n; i++) s.push(i);
        while(s.size() > 1){
            int ele1 = s.top();
            s.pop();
            int ele2 = s.top();
            s.pop();
            
            if(v[ele1][ele2] == 1){
                s.push(ele2);
            } else{
                s.push(ele1);
            }
        }
        int ele = s.top();
        
        //it should follow no one
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(v[ele][i] == 1){
                flag = false;
                break;
            }
        }
        if(!flag) return -1;
        
        for(int i = 0; i < n; i++){
            if(i == ele) continue;
            if(v[i][ele] == 0){
                flag = false;
                break;
            }
        }
        return flag == false ? -1 : ele;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends