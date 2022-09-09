//TC : O(N)
//SC : O(N)

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char ch)
{
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

string prefixToPostfix(string prefix)
{
	stack<string>st;

	for (int i = prefix.length() - 1 ; i >= 0; i--)
	{
		if (isOperand(prefix[i]))
		{
			string opr(1, prefix[i]);
			st.push(opr);
		}
		else
		{
			string op1 = st.top();
			st.pop();

			string op2 = st.top();
			st.pop();

			string exp = op1 + op2 + prefix[i];
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

	string prefix;
	getline(cin, prefix);

	string postfix = prefixToPostfix(prefix);

	cout << "Postfix of " << prefix << " : " << postfix << endl;

	return 0;
}
