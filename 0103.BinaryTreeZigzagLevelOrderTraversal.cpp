// Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Approach: DFS with unordered map

class Solution {
public:
    int maxDepth = 0;
    
    // DFS Traversal for inserting nodes in vector
    void dfs(TreeNode *root, int level,
             unordered_map<int, vector<int> > &M) {
        
        if(root==NULL) return ;
        
        // Update maximum Depth
        maxDepth = max(maxDepth, level);
        
        // Insert into current index vector
        M[level].push_back(root->val);
        
        // Left and Right recursively traverse
        dfs(root->left, level + 1, M);
        dfs(root->right, level + 1, M);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        // if root is NULL
        if(root==NULL) return {};
        
        unordered_map<int, vector<int> > M;
        
        // Perform DFS Traversal
        dfs(root, 0, M);
        
        // To store the result
        vector<vector<int>> Ans(maxDepth + 1);        
        
        // Traverse the Map
        for(int i = 0; i <= maxDepth; i++) {
            
            // If index is current index is odd
            // then reverse the vector
            if(i&1) {
                reverse(M[i].begin(), M[i].end());
            }
            
            // Update the vector at that index
            Ans[i] = M[i];
        }
        
        // Return the result
        return Ans;
    }
};