// Moris Inorder Traversal
// TC : O(N) Amortised
// SC : O(1)


class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        vector<int>inorder;
        
        Node* currentNode = root;
        
        while(currentNode)
        {
            if(currentNode->left == NULL)
            {
                inorder.push_back(currentNode->data);
                currentNode = currentNode->right;
            }
            else
            {
                Node* prev = currentNode->left;
                
                while(prev->right && prev->right != currentNode)
                {
                    prev = prev->right;
                }
                
                if(prev->right == NULL) // left subtree has not been visited, therefore mark the thread and move to left
                {
                    prev->right = currentNode;
                    currentNode = currentNode->left;
                }
                else // that means thread already exists, i.e. Left Subtree has already been visited. Since Left ST is visited, you're at root now, so print the value.  Now cut the thread and go to right since Left ST is visited and root is also done.
                    // Inorder : Left Root Right
                {
                    inorder.push_back(currentNode->data);
                    prev->right = NULL;
                    currentNode = currentNode->right;
                }
            }
        }
        
        return inorder;
    }
};
