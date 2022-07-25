// Recursive N-ARY Inorder Traversal
// TC : O(N)
// SC : O(N)

class Solution {
public:
    vector<int> inorder(Node* root) {
        vector<int>nodes;
        
        if(!root)
            return nodes;
        
        inorderT(root, nodes);
        return nodes;
    } 
    
    void inorderT(Node* root, vector<int>&nodes)
    {
        if(!root)
            return;
        
        Node* currNode = root;
        
        for(int i = 0 ; i < currNode->children.size()-1 ; i++)
        {
            inorderT(currNode->children[i],nodes); //Visiting 1 till n-1 children
        }
        nodes.push_back(currNode->val);
      
        inorderT(currNode->children[currNode->children.size()-1],nodes); //Visinting last child
    }
  
    
};
