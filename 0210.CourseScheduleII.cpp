// Problem Link: https://leetcode.com/problems/course-schedule-ii/
// Approach: BFS - Topological Sort

class Solution {
public:
    vector<int> findOrder(int numCourses, 
                          vector<vector<int>>& prerequisites) {
        
        vector<int> Ans;
        
        // Adjacency List
        vector<int> Adj[numCourses];
        vector<int> inDegree(numCourses, 0);
        
        // Create Adjacency List
        for(auto &it : prerequisites) {
            Adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }
        
        queue<int> Q;
        
        // Store the node whose inDegree is 0
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i]==0) Q.push(i);
        }
        
        // Until queue is empty
        while(!Q.empty()) {
            
            // Get the source
            int src = Q.front();
            
            // Push the node in the
            // resultant Ans
            Ans.push_back(src);
            Q.pop();
            
            // Traverse the child nodes
            // of src
            for(auto &child : Adj[src]) {
                
                inDegree[child]--;
                
                // If the inDegree is 0
                // then append this node
                // to the queue
                if(inDegree[child]==0) {
                    Q.push(child);
                }
                
            }
            
        }
        
        // Check if Topological Sort
        // exists or not
        if(Ans.size()!=numCourses) return {};
        return Ans;
    }
};