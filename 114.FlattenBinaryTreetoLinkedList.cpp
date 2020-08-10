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
// Problem Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Approch: Recursive Approach
class Solution {
public:
    void flatten(TreeNode* root) {
        
        // If reach NULL node aur a node which
        // is the leaf node
        if(root==NULL 
           || (root->left==NULL 
               && root->right==NULL)) {
            return ;
        }
        
        // Recursively move to left child
        // of root and flatten the left side 
        // of tree
        if(root->left!=NULL) {
            
            // Flatten left tree of root node
            flatten(root->left);
            
            // Store the right
            TreeNode *temp = root->right;
            
            // Store left to the right Tree
            root->right = root->left;
            root->left = NULL;
            
            TreeNode *traversing = root->right;
            
            // Traverse right untill end
            while(traversing->right!=NULL) {
                traversing = traversing->right;
            }
            
            // Update the last of new right node
            // to the previous right
            traversing->right = temp;
            
        }
        
        // Flatten the right node
        flatten(root->right);
        
    }
};