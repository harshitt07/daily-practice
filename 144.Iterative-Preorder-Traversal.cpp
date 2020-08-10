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
// Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Approach: Iterative-Preorder-Traversal
class Solution {
public:
    
    // Node Left Right
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> Ans;
        TreeNode *temp = root;
        stack<TreeNode *> Stack;
        
        while(temp!=NULL || !Stack.empty()) {
            
            while(temp!=NULL) {
                
                // Node 
                Ans.push_back(temp->val);
                
                // Left 
                Stack.push(temp);
                temp = temp->left;
            }
            TreeNode *curr = Stack.top();
            Stack.pop();
            
            // Right
            temp = curr->right;            
        }
        return Ans;        
    }
};
