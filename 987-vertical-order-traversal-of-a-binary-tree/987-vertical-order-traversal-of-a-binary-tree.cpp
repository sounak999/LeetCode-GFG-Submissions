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
    void solve(TreeNode* root, map<int, map<int, multiset<int> > > &mp, int hd, int lvl)
    {
        if(!root)
            return ;
        
        mp[hd][lvl].insert(root->val);
        // left
        solve(root->left, mp, hd-1, lvl+1);
        // right
        solve(root->right, mp, hd+1, lvl+1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // horizontal distance, level-wise distance
        map<int, map<int, multiset<int> > > mp;
        vector<vector<int>> res;
        
        // horizontal and level-wise distance
        int hd = 0, lvl = 0;
        solve(root, mp, hd, lvl);
        
    
        for (auto column : mp) 
        {
            vector<int> col;
            for (auto rows : column.second) 
                col.insert(col.end(), rows.second.begin(), rows.second.end());
            
            res.push_back(col);
        }
        
        return res;
    }
};