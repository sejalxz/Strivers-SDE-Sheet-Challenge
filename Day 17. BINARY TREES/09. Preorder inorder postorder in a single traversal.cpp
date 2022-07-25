// Recursive
// TC : O(N)
// SC : O(N)

void traversal(BinaryTreeNode<int> *root, vector<int>&pre, vector<int>&in, vector<int>&post)
{
    if(!root)
        return;
    
    pre.push_back(root->data);
    traversal(root->left, pre, in, post);
    in.push_back(root->data);
    traversal(root->right, pre, in, post);
    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>>traversals;
    if(!root)
        return traversals;
    
    vector<int>in,pre,post;
    
    traversal(root,pre,in,post);
    
    traversals.push_back(in);
    traversals.push_back(pre); 
    traversals.push_back(post);
    
    return traversals;
}

// Iterative
// TC : O(3xN)
// SC : O(3xN) or O(4xN)

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>>traversals;
    if(!root)
        return traversals;
    
    vector<int>in,pre,post;
    
    stack<pair<BinaryTreeNode<int>*,int>>st;
    st.push({root,1});
    
    while(!st.empty())
    {
        auto it = st.top();
        st.pop();
        
        if(it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left != NULL)
            {
                st.push({it.first->left,1});
            }
        }
        else if(it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != NULL)
            {
                st.push({it.first->right,1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    
    traversals.push_back(in);
    traversals.push_back(pre);
    traversals.push_back(post);
    
    return traversals;
}
