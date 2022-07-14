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
    TreeNode* solve(vector<int>& post, int& idx, int s, int e, unordered_map<int,int> &mp)
    {
        if(idx < 0 || s > e)
            return NULL;
        
        int pos = mp[post[idx]];
        TreeNode* root = new TreeNode(post[idx--]);
        
        root->right = solve(post, idx, pos+1, e, mp);
        root->left = solve(post, idx, s, pos-1, mp);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1, inStart = 0, inEnd = inorder.size()-1;
        unordered_map<int, int> mp;
        
        for(int i=0; i<=inEnd; i++) {
            mp[inorder[i]] = i;
        }
        
        return solve(postorder, idx, inStart, inEnd, mp);
    }
};