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


// Iterative BT Postorder Traversal

// TC : O(N)
// SC : O(H) (Auxilary Stack)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>nodes;
        stack<TreeNode*>st;
        
        if(!root)
            return nodes;
        
        st.push(root);
        addLeftSubTree(root, st);
        
        while(!st.empty())
        {
            TreeNode* currNode = st.top();
            st.pop();
                             
            nodes.push_back(currNode->val);
            
            if(currNode->right)
            {
                st.push(currNode->right);
                addLeftSubTree(currNode->right,st);
            }        
        }
        return nodes;
    }
    
    void addLeftSubTree(TreeNode* root, stack<TreeNode*>&st)
    {
        if(root->left){
            TreeNode* currentNode = root->left;
            
            while(currentNode)
            {
                st.push(currentNode);
                currentNode = currentNode->left;
            }
        }
        
    }
};
