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
// Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Approach: Iterative-Inorder-Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        // Rule: Left Node Right
        
        vector<int> Ans;
        TreeNode *temp = root;
        stack<TreeNode *> Stack;
        
        while(temp!=NULL || !Stack.empty()) {
            
            while(temp!=NULL) {
                Stack.push(temp);
                
                // Left 
                temp = temp->left;
            }
            
            TreeNode *curr = Stack.top();
            Stack.pop();
            
            // Node
            Ans.push_back(curr->val);
            
            // Right
            temp = curr->right;           
        }
        return Ans;
    }
};
