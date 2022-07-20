//There can never be two celebrities
//Brute
//TC : O(N^2)
//SC : O(2N)

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int>inDegree(n+1, 0);
        vector<int>outDegree(n+1, 0);
        for(int out = 0 ; out < n ; out++){
            for(int in = 0 ; in < n ; in++){
                if(M[out][in] == 1)
                {
                    inDegree[in]++;
                    outDegree[out]++;
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            if(inDegree[i] == n-1 && outDegree[i] == 0)
            return i;
        }
        
        return -1;
    }
};

//Brute - II
//TC : O(N^2)
//SC : O(1)

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& A, int n) 
    {
        bool isKnown, knowsAnyone;
        int celeb = -1;
        for(int i = 0 ; i < n ; i++)
        {
            isKnown = true;
            knowsAnyone = false;
            
            for(int j = 0 ; j < n ; j++)
            {
                if(i==j)
                    continue;
                    
                if(A[i][j] == 1){
                    knowsAnyone = true;
                    break;
                }
                    
                if(A[j][i] == 0)
                {
                    isKnown = false;
                    break;
                }
            }
            if(!knowsAnyone && isKnown){
                celeb = i;
                break;
            }
            
        }
        return celeb;
    }
};

//OPTIMAL
// TC : O(N)
// SC : O(N)

#include <stack>
int findCelebrity(int n) {
    
    stack<int>st;
        for(int i = 0 ; i < n ; i++)
            st.push(i);
            
            
        while(st.size()>1)
        {
            int j = st.top();
            st.pop();
            
            int i = st.top();
            st.pop();
            
            if(knows(i,j) == true)
                st.push(j);
            else
                st.push(i);
        }
        
        int potentialCeleb = st.top();
        st.pop();
        
        for(int i = 0 ; i < n ; i++)
        {
            if(i != potentialCeleb)
            {
                if(knows(potentialCeleb,i) == true || knows(i,potentialCeleb) == false)
                    return -1;
            }
            
        }
        return potentialCeleb;  
        
}
