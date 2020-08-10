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
// Problem Link: https://leetcode.com/problems/find-bottom-left-tree-value/
// Approach: Recursive - DFS Traversal
class Solution {
public:
    
    void dfs(TreeNode* root, int l, int &level, int &value) {
        if(root==NULL) return ;
        if(level < l) {
            level = l;
            value = root->val;
        }
        dfs(root->left, l + 1, level, value);
        dfs(root->right, l + 1, level, value);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int level = -1;
        int value;
        dfs(root, 0, level, value);
        return value;
    }
};