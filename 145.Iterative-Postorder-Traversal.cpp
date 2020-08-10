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
// Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Approach: Iterative-Postorder-Traversal
class Solution {
public:
    
    vector<int> usingTwoStack(TreeNode *root) {
        
        stack<TreeNode *> S1, S2;
        
        // Push root to stack S1
        S1.push(root);
        
        // Iterate till S1 is not empty
        while(!S1.empty()) {
            
            TreeNode *temp = S1.top();
            S1.pop();
            
            // Push the Node part in Stack S2
            // such that the reverse order will
            // give Postorder Traversal
            S2.push(temp);
            
            // Left and Right Node to Stack S1
            if(temp->left) S1.push(temp->left);
            if(temp->right) S1.push(temp->right);
            
        }
        
        vector<int> Ans;
        
        // Pop from stack S2 which will
        // give Postorder-Traversal
        while(!S2.empty()) {
            TreeNode *temp = S2.top();
            Ans.push_back(temp->val);
            S2.pop();
        }
        
        return Ans;
        
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        // Rule: Left Right Node
        
        if(root==NULL) return {};
        
        return usingTwoStack(root);
        // return usingOneStack(root);
        
    }
};
