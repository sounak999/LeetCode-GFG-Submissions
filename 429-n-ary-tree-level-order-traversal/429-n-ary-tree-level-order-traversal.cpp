/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        if(!root)
            return res;
        
        queue<Node*> q;
        q.push(root);
        
        while(q.size())
        {
            int size = q.size();
            vector<int> temp;
            
            for(int i=0; i<size; i++)
            {
                Node* frontNode = q.front();
                temp.push_back(frontNode->val);
                q.pop();
                
                for(Node* child: frontNode->children)
                    q.push(child);
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
};