// Problem Link: https://leetcode.com/problems/course-schedule/
// Approach: Backtracking + DFS

class Solution {
public:
    
    // DFS Traversal to check cycle with node src
    bool dfs(int src, int parent, 
             vector<int> Adj[], vector<bool> &vis) {
        
        // Mark current node as visited
        vis[src] = true;
        
        // Traverse the Adjacency List of
        // current node src
        for(auto &child : Adj[src]) {
            
            // Recursive DFS Call for child
            // node with src node as parent
            // for child node
            if(!vis[child]) {
                
                // If return true then
                // cycle is found
                if(dfs(child, src, Adj, vis)) {
                    return true;
                }
            } else {
                return true;
            }
        }
        
        // For Backtracking make src as false
        vis[src] = false;
        
        // Return false, if no cycle is detected
        // for this DFS call for src node
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int N = numCourses;
        
        // return true;
        
        // For adjacency list
        vector<int> Adj[N];
        
        // Create Directed Graph
        for(auto &it : prerequisites) {
            Adj[it[1]].push_back(it[0]);            
        }
        
        vector<bool> vis(N, false);
        
        for(int i = 0; i < N; i++) {
            
            // Check cycle using DFS
            // If found then return false
            if(!vis[i]) {
                if(dfs(i, -1, Adj, vis)) {
                    return false;
                }
            }
        }
        
        // It means Cycle Not found
        return true;
    }
};