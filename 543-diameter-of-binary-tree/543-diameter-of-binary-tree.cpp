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
    int depth(TreeNode* root, int& diameter)
    {
        if(!root)
            return 0;
        
        int leftPart = depth(root->left, diameter);
        int rightPart = depth(root->right, diameter);
        
        diameter = max(diameter, leftPart + rightPart);
        
        return 1 + max(leftPart, rightPart);
    }
    
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }
};