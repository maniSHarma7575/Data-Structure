#include<bits/stdc++.h>
//static BinaryTreeNode<int>* prev=NULL;
bool isBSTE(BinaryTreeNode<int>* root,int maxima,int minima)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data<minima || root->data>maxima)
    {
        return false;
    }
    bool leftsearch=isBSTE(root->left,root->data,minima);
    bool rightsearch=isBSTE(root->right,maxima,root->data);
    return leftsearch&rightsearch;
}
bool isBST(BinaryTreeNode<int>* root)
{
    return isBSTE(root,INT_MAX,INT_MIN);
}
