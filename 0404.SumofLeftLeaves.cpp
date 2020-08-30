// Problem Link: https://leetcode.com/problems/sum-of-left-leaves/
// Approach: DFS Traversal on Tree without using helper function
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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        // If root NULL, return 0
        if(root==NULL) return 0;
        
        // Check if root->left forms a valid
        // leaf node then add this value and
        // recursively call with sum with
        // right child
        if(root->left) {
            if(root->left->left==NULL
               && root->left->right==NULL) {
                return (root->left->val
                      + sumOfLeftLeaves(root->right));
            }
        }
        
        // Recursively for left and right subtree
        return sumOfLeftLeaves(root->left)
             + sumOfLeftLeaves(root->right);
        
    }
};