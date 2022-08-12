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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = max(p->val, q->val);
        int b = min(p->val, q->val);
        
        while(root)
        {
            if(root->val > a)
                root = root->left;
            else if(root->val < b)
                root = root->right;
            else
                return root;
        }
        
        return NULL;
    }
};