bool isValidParenthesis(string exp)
{
    stack<char>st;
    for(int i = 0 ; i < exp.length() ; i++)
    {
        if(exp[i] == '(' or exp[i] == '{' or exp[i] == '[' )
            st.push(exp[i]);
        else
        {
            if(st.empty())
                return false;
            else
            {
                char currentChar = st.top();
                st.pop();
                 if( (exp[i] == ')' && currentChar == '(') || (exp[i] == '}' && currentChar == '{') || (exp[i] == ']' && currentChar == '[') )
                 {
                     continue;
                 }
                else
                {
                    return false;
                }
            }
        }
    }
    if(st.empty())
        return true;
    
    return false;
}
