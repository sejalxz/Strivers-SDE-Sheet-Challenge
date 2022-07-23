// Recursive Postorder Traversal of N-ary Tree

// TC : O(N)
// SC : O(N) //Skewed O(N)

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>nodes;
        
        if(!root)
            return nodes;
        
        postorderT(root, nodes);
        
        return nodes;
    }
    
    void postorderT(Node* root, vector<int>&nodes){
        if(!root)
            return;

        for(auto child : root->children)
        {
            postorderT(child,nodes);
        }
        
        nodes.push_back(root->val);
    }
    
};

// Iterative Postorder Traversal of N-ary Tree

// TC : O(N)
// SC : O(N) //Skewed O(N)

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>nodes;
        
        if(!root)
            return nodes;
        
        stack<Node*>st;
        st.push(root);
        
        while(!st.empty())
        {
            Node *currNode = st.top();
            st.pop();
            for(int i=0 ; i<currNode->children.size() ; i++)
            {
                st.push(currNode->children[i]);
            }
            nodes.push_back(currNode->val);
        }
        reverse(nodes.begin(), nodes.end());
        return nodes;
    } 
  
    
};
