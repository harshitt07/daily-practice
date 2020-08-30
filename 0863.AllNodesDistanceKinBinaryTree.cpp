// Problem Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Approach: DFS without extra space :)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    // To store all the nodes which are K distance
    // from target node
    vector<int> Ans;
    
    // DFS tarversal to find the all the K
    // distance node from current level l
    void dfs2(TreeNode *root, int l, int K) {
        
        // If reaches NULL
        if(root==NULL) {
            return ;
        }
        
        // If at Kth level
        if(l==K) {
            Ans.push_back(root->val);
            return ;
        }
        
        // Left and Right Recursive traversal
        dfs2(root->left, l + 1, K);
        dfs2(root->right, l + 1, K);
    }
    
    // DFS Traversal to find the target and
    // then recursively return the level in
    // increasing order of the distance from
    // target node
    int dfs1(TreeNode *root, TreeNode *target, int K) {
        
        // If NULL i.e., target is not found
        // then return "-1"
        if(root==NULL) {
            return -1;
        }
        
        // If target node is found then call
        // dfs2 for all the Kth node from this
        // target node and return 1 as the above
        // node of this target node is at level 1
        else if(root==target) {
            dfs2(target, 0, K);
            return 1;
        } 
        
        // Recursively traverse for Left and
        // Right Tree
        else {
            int L = dfs1(root->left, target, K);
            int R = dfs1(root->right, target, K);
            
            // If target is found in the left
            // subtree of the current root node
            if(L!=-1) {
                
                // Insert the Kth level node
                if(L==K) {
                    Ans.push_back(root->val);
                }
                
                // Reursively dfs2 to for Kth
                // node from current level L
                dfs2(root->right, L + 1, K);
                return L + 1;
            } 
            
            
            // If target is found in the right
            // subtree of the current root node
            else if(R!=-1) {
                
                // Insert the Kth level node
                if(R==K) {
                    Ans.push_back(root->val);
                }
                // Reursively dfs2 to for Kth
                // node from current level R
                dfs2(root->left, R + 1, K);
                return R + 1;
            }
            
            // Else no target is found
            else {
                return -1;
            }
            
        }
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        // DFS Traversal
        dfs1(root, target, K);
        return Ans;
    }
};