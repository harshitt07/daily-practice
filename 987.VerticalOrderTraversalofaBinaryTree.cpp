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

// Problem Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Approach: DFS with STL 

class Solution {
public:
    
    // x is distance, y is level and z is val    
    struct Punter {
        int x, y, z;
    };
    vector<Punter> Ponting;
    
    static bool cmp(Punter &a, Punter &b) {
        
        if(a.x == b.x) {
            
            if(a.y==b.y) {
                return a.z < b.z;
            }
            
            return a.y < b.y;            
        }
        
        return a.x < b.x;        
    }
    
    void dfs(TreeNode* root, int dist, int level) {
        if(root==NULL) {
            return ;
        }
        Ponting.push_back({dist, level, root->val});
        dfs(root->left, dist - 1, level + 1);
        dfs(root->right, dist + 1, level + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(root==NULL) return {};
        
        dfs(root, 0, 0);        
        sort(Ponting.begin(), Ponting.end(), cmp);
        
        int prev = Ponting[0].x;
        int i = 1;
        vector<vector<int> > Ans;
        vector<int> A;
        
//         for(int i = 0; i < Ponting.size(); i++) {
//             cout << Ponting[i].x << ' ' << Ponting[i].y << ' ' << Ponting[i].z << endl;
//         }
        
        for(int i = 0; i < Ponting.size(); ) {
            
            do {
                A.push_back(Ponting[i++].z);
            } while(i < Ponting.size() && Ponting[i].x == Ponting[i-1].x);
            
            Ans.push_back(A);
            
            A.clear();
            
        }        
        return Ans;
    }
};