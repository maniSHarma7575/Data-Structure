#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool equalbrackets(string s)
{
	stack<char> st;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(' || s[i]=='{' || s[i]=='[')
		{st.push(s[i]);
			continue;
		}
		if(st.empty())
			return false;
		
		switch(s[i])
		{
			case ')':
			if(st.top()!='(')return false;
			st.pop();
			break;
			case '}':
			if(st.top()!='{')return false;
			st.pop();
			break;
			case ']':
			if(st.top()!='[')return false;
			st.pop();
			break;
		}
		
	}
	if(st.empty())
	{
		return true;
	}
	return false;
}
int main() {
 string exp="{()}[]";
 cout<<equalbrackets(exp);
	return 0;
}
