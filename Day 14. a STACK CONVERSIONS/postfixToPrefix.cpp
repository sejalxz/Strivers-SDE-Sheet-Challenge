//TC : O(N)
//SC : O(N)

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return true;
	return false;
}

string postfixToPrefix(string postfix)
{
	stack<string>st;

	for (int i = 0 ; i < postfix.length() ; i++)
	{
		if (isOperand(postfix[i]))
		{
			string opr(1, postfix[i]);
			st.push(opr);
		}
		else {
			string op2 = st.top();
			st.pop();

			string op1 = st.top();
			st.pop();

			string exp = postfix[i] + op1 + op2;
			st.push(exp);
		}
	}
	return st.top();
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string postfix;
	getline(cin, postfix);

	string prefix = postfixToPrefix(postfix);
	cout << "Prefix expression of " << postfix << " : " << prefix;


	return 0;
}
