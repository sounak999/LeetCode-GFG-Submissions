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
    TreeNode* solve(vector<int>& pre, vector<int>& in, int &preIdx, int s, int e, unordered_map<int, int> &mp)
    {
        if(preIdx == pre.size() || s > e)
            return NULL;
        
        int element = pre[preIdx++];
        TreeNode* root = new TreeNode(element);
        int pos = mp[element];
        root->left = solve(pre, in, preIdx, s, pos-1, mp);
        root->right = solve(pre, in, preIdx, pos+1, e, mp);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0, inStart = 0, inEnd = inorder.size()-1;
        unordered_map<int, int> mp;
        for(int i=0; i<= inEnd; i++) {
            mp[inorder[i]] = i;
        }
        return solve(preorder, inorder, preIdx, inStart, inEnd, mp);
    }
};