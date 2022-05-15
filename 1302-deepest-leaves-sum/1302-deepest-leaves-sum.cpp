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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        
        int sum = 0;
        
        while(!q.empty()){
            int size = q.size(); 
            sum = 0;
			//sum is used to add node values at each level 
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                sum += front->val;
                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
            }
        }
        
		//return sum of node values at last level 
        return sum;
    }
};