// Recursive 
// TC : O(N)
// SC : O(H)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return 1 + max(left , right);
    }
};

// Iterative 
// TC : O(N)
// SC : O(N) Stack

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(!root)
            return depth;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            depth++;
            int nodes = q.size();
            
            while(nodes--)
            {
                TreeNode* currNode = q.front();
                q.pop();
                
                if(currNode->left)
                    q.push(currNode->left);
                
                if(currNode->right)
                    q.push(currNode->right);
            }
        }
        
        return depth;
    }
};
