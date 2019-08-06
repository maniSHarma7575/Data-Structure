#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool isOperator(char x)
{
	if(x=='+' || x=='-'|| x=='/'|| x=='*' || x=='^')return true;
	else return false;
}
string preToPost(string pre)
{
	stack<string> s;
	int length=pre.length();
	for(int i=length-1;i>=0;i--)
	{
		if(isOperator(pre[i]))
		{
			string op1=s.top(); s.pop();
			string op2=s.top(); s.pop();
			string temp=op1+op2+pre[i];
			s.push(temp);
		}
		else
		{
			s.push(string(1,pre[i]));
		}
	}
	
	return s.top();
}
int main() {
	string pre="*+AB-CD";
	cout<<preToPost(pre);
	return 0;
}
