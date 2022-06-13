#https://practice.geeksforgeeks.org/problems/sort-a-stack/1

class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertNum(stack<int> &s, int temp)
{
    if(s.size() == 0 || s.top() <= temp)
    {
        s.push(temp);
        return;
    }
    
    int val = s.top();
    s.pop();
    insertNum(s, temp);
    s.push(val);
    return;
}

void SortedStack :: sort()
{
    if(s.size() == 0)
        return;
        
    int temp = s.top();
    s.pop();
    sort();
    insertNum(s, temp);
    return;
}
