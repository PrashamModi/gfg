//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        sort(meetings.begin(),meetings.end());
        
        priority_queue<int,vector<int>,greater<>>freerooms;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>busyrooms;
        
        vector<int>freq(n,0);
        
        for(int i=0;i<n;i++){
            freerooms.push(i);
        }
        
        for(auto it:meetings){
            int st=it[0];
            int et=it[1];
            while(!busyrooms.empty() && busyrooms.top().first <= st){
                freerooms.push(busyrooms.top().second);
                busyrooms.pop();
            }
            if(!freerooms.empty()){
                int room=freerooms.top();
                freerooms.pop();
                freq[room]++;
                busyrooms.push({et,room});
            }
            else{
                int t=busyrooms.top().first;
                int room_idx=busyrooms.top().second;
                t+=(et-st);
                busyrooms.pop();
                busyrooms.push({t,room_idx});
                freq[room_idx]++;
            }
        }
        
        int max_room_used=0;
        for(int i=1;i<n;i++){
            if(freq[i]>freq[max_room_used]){
                max_room_used=i;
            }
        }
        return max_room_used;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends