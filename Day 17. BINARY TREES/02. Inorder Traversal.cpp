// Recursive

//TC : O(N)
//SC : O(H) -> RecStack

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>nodes;
        inorderT(root, nodes);
        return nodes;
    }
    
private:
    void inorderT(TreeNode* root, vector<int>&nodes){
        if(root == nullptr)
            return;
        
        inorderT(root->left, nodes);
        nodes.push_back(root->val);
        inorderT(root->right, nodes);
    }
};
