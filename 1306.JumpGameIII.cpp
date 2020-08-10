// Problem Link: https://leetcode.com/problems/jump-game-iii/
// Approach: Iterative - BFS
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        queue<int> Q;
        Q.push(start);
        int N = arr.size();
        
        vector<int> vis(N, false);
        
        // Until Queue is empty
        while(!Q.empty()) {
            
            int currIndex = Q.front();
            Q.pop();
            
            // If value found
            if(arr[currIndex]==0) return true;
            
            vis[currIndex] = true;
            
            // Left side of the index
            if(currIndex + arr[currIndex] < N) {
                if(!vis[currIndex + arr[currIndex]]) 
                    Q.push(currIndex + arr[currIndex]);
            }
            
            // Right side of the index
            if(currIndex - arr[currIndex] >= 0) {                
              if(!vis[currIndex - arr[currIndex]])
                  Q.push(currIndex - arr[currIndex]);
            }
            
        }
        return false;        
    }
};