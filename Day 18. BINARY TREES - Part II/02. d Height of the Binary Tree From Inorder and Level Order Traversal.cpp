//  Time Complexity: O(N^2)
//  Space Complexity: O(N)

#include<queue>

struct Node
{
    int height;
    int leftIndex;
    int rightIndex;
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    
    queue<Node>q;
    int maxHeight = 0;
    
    Node init;
    init.height = 0;
    init.leftIndex = 0;
    init.rightIndex = N-1;
    
    q.push(init);
    
    for(int i = 0 ; i < N; i++)
    {
        int currNodeVal = levelOrder[i];
        Node currNode = q.front();
        q.pop();
        
        int currPos; 
        
        for(int j = currNode.leftIndex; j <= currNode.rightIndex ; j++)
        {
            if(currNodeVal == inorder[j]){
               currPos = j;
            }
        }
        
        if(currPos > currNode.leftIndex)//LC exists
        {
            Node newNode;
            newNode.height = currNode.height + 1;
            
            maxHeight = max(newNode.height, maxHeight);
            
            newNode.leftIndex = currNode.leftIndex;
            newNode.rightIndex = currPos-1;            
            
            q.push(newNode);
        }
        
        if(currPos < currNode.rightIndex)//RC exists
        {
            Node newNode;
            newNode.height = currNode.height + 1;
            
            maxHeight = max(newNode.height, maxHeight);
            
            newNode.leftIndex = currPos+1;
            newNode.rightIndex = currNode.rightIndex;
            
           
            q.push(newNode);
        }
    }
    
    return maxHeight;
}

// Reducing the complexity by storing index positions of inorder array
//  Time Complexity: O(N)
//  Space Complexity: O(N + N)

#include<queue>
#include<unordered_map>

struct Node
{
    int height;
    int leftIndex;
    int rightIndex;
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    
    queue<Node>q;
    unordered_map<int,int>mp;
    int maxHeight = 0;
    
    Node init;
    init.height = 0;
    init.leftIndex = 0;
    init.rightIndex = N-1;
    
    q.push(init);
    
    for(int i = 0 ; i < N ; i++)
    {
        int key = inorder[i];
        mp[key] = i;
    }
    
    for(int i = 0 ; i < N; i++)
    {
        int currNodeVal = levelOrder[i];
        Node currNode = q.front();
        q.pop();
        
        int currPos = mp[currNodeVal]; 
        
        if(currPos > currNode.leftIndex)//LC exists
        {
            Node newNode;
            newNode.height = currNode.height + 1;
            newNode.leftIndex = currNode.leftIndex;
            newNode.rightIndex = currPos-1;  
            
            maxHeight = max(newNode.height, maxHeight);
            q.push(newNode);
        }
        
        if(currPos < currNode.rightIndex)//RC exists
        {
            Node newNode;
            newNode.height = currNode.height + 1;
            newNode.leftIndex = currPos+1;
            newNode.rightIndex = currNode.rightIndex;
            
            maxHeight = max(newNode.height, maxHeight);
            q.push(newNode);
        }
    }
    
    return maxHeight;
}
