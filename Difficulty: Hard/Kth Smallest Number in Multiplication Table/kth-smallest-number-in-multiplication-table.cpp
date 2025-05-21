class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        int low = 1;
        int high = m*n;
        int ans = m*n;
        while(low <= high){
            int mid = low + (high - low)/2;
            int count = 0; // Will store count of elements in the matrix smaller than or equal to mid 
            // We will find elements from each row
            // Rows and columns are 1-indexed
            for(int i = 1; i <= m; i++){
                count += min(mid/i, n); 
            }
            
            if(count >= k){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
