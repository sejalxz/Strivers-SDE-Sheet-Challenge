// TC : O(N)
// SC : O(N)

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        
        int maxHeight = 0;
        
        for(int i = 0 ; i < root->children.size() ; i++)
        {
            int height = maxDepth(root->children[i]);
            maxHeight = max(height, maxHeight);
        }
        return 1 + maxHeight;
    }
};
