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
    void solve(TreeNode* root, int depth, vector<int>& v)
    {
        if(root == NULL)
            return ;
        
        if(depth > v.size())
            v.push_back(root->val);
        
        // for right view, go to right child 
        solve(root->right, depth+1, v);
        
        // then left child
        solve(root->left, depth+1, v);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 1, ans);
        return ans;
    }
};