/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//  Problem Link: https://leetcode.com/problems/path-sum-ii/
//  Approach: Recursive DFS
class Solution {
public:
    
    // Function to implement the DFS Traversal
    void dfs(TreeNode* root, int sum, 
             vector<vector<int> > &finalAns, 
             vector<int> A) {
        
        // if root is NULL
        if(root==NULL) return ;
        
        // Decrement from the sum and
        // include this in the vector A
        sum -= root->val;
        A.push_back(root->val);
        
        // If sum is zero and it
        // reaches the leaf node
        if(sum==0) {
            
            // If leaf node then push vector
            // into vector finalAns
            if(root->left==NULL 
               && root->right==NULL) {
                finalAns.push_back(A);
            }
        }
        
        // Left and Right recursive call
        dfs(root->left, sum, finalAns, A);
        dfs(root->right, sum, finalAns, A);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        // To store the final vectors
        vector<vector<int>> finalAns;
        vector<int> A;
        
        // DFS Traversal
        dfs(root, sum, finalAns, A);
        
        return finalAns;
    }
};