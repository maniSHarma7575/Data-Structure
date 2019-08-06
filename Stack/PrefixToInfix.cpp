#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool isOperator(char x)
{
	if( x=='+' || x=='-' || x=='/' || x=='*')return true;
	else return false;
}
string prefixToInfix(string pre)
{
	stack<string> s;
	int length=pre.length();
	for(int i=length-1;i>=0;i--)
	{
		if(isOperator(pre[i]))
		{
			string op1=s.top(); s.pop();
			string op2=s.top(); s.pop();
			string temp="("+op1+pre[i]+op2+")";
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
	// your code goes here
	string pre="*-A/BC-/AKL";
	cout<<"Infix :"<< prefixToInfix(pre);
	return 0;
}
