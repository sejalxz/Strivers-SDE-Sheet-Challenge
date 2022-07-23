// Recursive

//TC : O(N)
//SC : O(H) -> RecStack  + Aux O(1)

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

// Iterative BT Preorder Traversal

// TC : O(N)
// SC : O(H) (Auxilary Stack)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>nodes;
        stack<TreeNode*>st;
        
        if(!root)
            return nodes;
        
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* currNode = st.top();
            st.pop();
            
            nodes.push_back(currNode->val);
            
            if(currNode->right)
                st.push(currNode->right);
            
            if(currNode->left)
                st.push(currNode->left);
        }
        return nodes;
    }
};
