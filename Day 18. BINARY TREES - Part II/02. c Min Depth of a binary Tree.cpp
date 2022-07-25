// Recursive 
// TC : O(N)
// SC : O(H)

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        return (left == 0 || right == 0) ? left + right + 1: 1 + min(left, right);
    }
};

// Iterative 
// TC : O(N)
// SC : O(N)

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        queue<TreeNode*>q;
        q.push(root);
        
        int height = 0;
        
        while(!q.empty())
        {
            height++;
            int size = q.size();
            
            while(size--)
            {
                TreeNode* currentNode = q.front();
                q.pop();
                
                if(currentNode->left)
                    q.push(currentNode->left);
                
                if(currentNode->right)
                    q.push(currentNode->right);
                
                if(currentNode->left == NULL && currentNode->right ==NULL)
                    return height;
            }
        }
        
        return -1;
    }
};
