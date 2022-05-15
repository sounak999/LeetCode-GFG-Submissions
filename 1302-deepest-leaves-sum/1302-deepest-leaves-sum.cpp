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
    void solve(TreeNode* root, int height, multimap<int, int> &mp)
    {
        if(root != NULL)
        {
            mp.insert(pair<int, int>(root->val, height));
            
            if(root->right)
                solve(root->right, height+1, mp);
            if(root->left)
                solve(root->left, height+1, mp);
        }
    }
    
    int getHeight(TreeNode* root)
    {
        if(root == NULL) 
            return 0;
        
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        int height = getHeight(root);
        
        multimap<int, int> mp;
        solve(root, 1, mp);
        
        int res = 0;
        for(auto it: mp)
        {
            if(it.second == height)
                res += it.first;
        }
        
        return res;
    }
};