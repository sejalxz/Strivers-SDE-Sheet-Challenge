// Recursive Preorder Traversal of N-ary Tree

// TC : O(N)
// SC : O(H)

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int>nodes;
        if(!root)
            return nodes;
        
        preorderT(root, nodes);
        return nodes;
    }
    
    void preorderT(Node* root, vector<int>&nodes)
    {
        if(!root)
            return;
        
        nodes.push_back(root->val);
        
        for(auto child : root->children)
        {
            preorderT(child,nodes);
        }
    }
};
