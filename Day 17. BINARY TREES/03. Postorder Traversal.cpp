// Recursive

//TC : O(N)
//SC : O(H) -> RecStack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorderT(root,nodes);
        return nodes;
    }
    
    void postorderT(TreeNode* root, vector<int>&nodes){
        if(root == nullptr)
            return;
          
        postorderT(root->left,nodes);
        postorderT(root->right,nodes);
        
        nodes.push_back(root->val);
        return;
    }
};
