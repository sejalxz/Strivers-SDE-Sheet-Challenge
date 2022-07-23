// Recursive Preorder Traversal of N-ary Tree

// TC : O(N)
// SC : O(N)

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


// Iterative Preorder Traversal of N-ary Tree

// TC : O(N)
// SC : O(N)

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int>nodes;
        
        if(!root)
            return nodes;
        
        stack<Node*>st;
        
        st.push(root);
        
        while(!st.empty())
        {
            Node* currNode = st.top();
            st.pop();
            
            nodes.push_back(currNode->val);
            
            for(int i = currNode->children.size()-1; i>=0 ; i--)
            {
                st.push(currNode->children[i]);
            }
        }
        
        return nodes;
    }
};
