#include<bits/stdc++.h>
int Ceil(BinaryTreeNode<int> *node, int input)
{
	if(!(node))
    {
        return INT_MIN;
	}
    if(node->data==input)
    {
        return input;
	}
    if(node->data<input)
    {
        return Ceil(node->right,input);
	}
    int ceilvalue=Ceil(node->left,input);
    return (ceilvalue>=input)?ceilvalue:node->data;
}
