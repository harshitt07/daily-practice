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
    
    bool canFinish(int numCourses, 
                   vector<vector<int>>& prerequisites) {
        
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

// Time Complexity: O(E + V^2)

// Problem Link: https://leetcode.com/problems/course-schedule/
// Approach: Optimized DFS with extra space
class Solution {
public:
    
    // DFS Traversal to check cycle with node src
    bool dfs(int src, vector<int> Adj[], 
             vector<bool> &vis, vector<bool> &checkedNode) {
        
        // If current node src is checked
        // then it doesn't contains cycle
        // with this node
        if(checkedNode[src]) return false;
       
        // Found Cycle
        if(vis[src]) return true;
        
        // Backtracking step
        vis[src] = true;
        
        bool ans = false;
        
        // Traverse the adjacency list
        // of src node
        for(auto &child : Adj[src]) {
            
            // Recursive Call for
            // child node
            ans = dfs(child, Adj, 
                           vis, checkedNode);
            
            // If cycle found then break;
            if(ans) break;
        }
        
        // Unmarked the node src
        vis[src] = false;
        
        // Marked this node as checked
        checkedNode[src] = true;
        
        return ans;        
    }
    
    bool canFinish(int numCourses, 
                   vector<vector<int>>& prerequisites) {
        
        int N = numCourses;
        
        // For adjacency list
        vector<int> Adj[N];
        
        // Create Directed Graph
        for(auto &it : prerequisites) {
            Adj[it[1]].push_back(it[0]);            
        }
        
        vector<bool> vis(N, false);
        vector<bool> checkedNode(N, false);
        
        for(int i = 0; i < N; i++) {
            
            // Check cycle using DFS
            // If found then return false
            if(dfs(i, Adj, vis, checkedNode)) {
                    return false;
                }
        }
        
        return true;
    }
};

// Time Complexity: O(E + V)
