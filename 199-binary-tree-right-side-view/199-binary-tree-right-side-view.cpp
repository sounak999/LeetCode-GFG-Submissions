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
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        
        while(!q.empty())
        {
            int n = q.size();
            TreeNode* frontLast = NULL;
            while(n--)
            {
                frontLast = q.front();
                q.pop();
                
                if(frontLast->left)
                    q.push(frontLast->left);
                if(frontLast->right)
                    q.push(frontLast->right);
            }
            
            ans.push_back(frontLast->val);
        }
        
        return ans;
    }
};