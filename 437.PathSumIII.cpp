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

// Problem Link: https://leetcode.com/problems/path-sum-iii/
// Approach: Recursive with Hashing

class Solution {
public:
    int cnt = 0;
    
    void dfs(TreeNode* root, int sum, 
             int currSum, 
             unordered_map<int, int> M) {
        
        if(root==NULL) return ;
        
        // Subarray with given sum K(here it is sum)
        currSum += root->val;
        if(currSum==sum) cnt++;
        if(M[currSum - sum] > 0) {
           cnt += M[currSum - sum];
        }
        M[currSum]++;
        
        dfs(root->left, sum, currSum, M);
        dfs(root->right, sum, currSum, M);       
    }
    
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> M;
        dfs(root, sum, 0, M);
        return cnt;
    }
};