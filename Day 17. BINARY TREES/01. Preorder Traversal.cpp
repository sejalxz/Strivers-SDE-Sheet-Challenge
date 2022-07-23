// Recursive

//TC : O(N)
//SC : O(H) -> RecStack

class Solution {    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>nodes;
        preorder(root, nodes);
        return nodes;
    }
    
    void preorder(TreeNode* root, vector<int> &nodes)
    {
        if(root == NULL)
            return;
        
        nodes.push_back(root->val);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }
};

