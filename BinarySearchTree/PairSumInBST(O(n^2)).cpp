// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
#include<bits/stdc++.h>
int search(BinaryTreeNode<int> *root,int se,int s)
{
    if(root==NULL)return -1;
    else
    {
        if(root->data<se)
        {
            return search(root->right,se,s);
        }
        else if(root->data>se)
        {
            return search(root->left,se,s);
        }
        else
        {
            root->data=INT_MAX;
            return se;
        }
    }
}
void printNodesSumToSee(BinaryTreeNode<int> *root,int s,BinaryTreeNode<int> *temp)
{
    if(root==NULL)return;
    printNodesSumToSee(root->left,s,temp);
    int sea=search(temp,(s-root->data),s);
   // cout<<root->data<<" "<<sea<<endl;
    if(sea!=-1 && sea!=(root->data))
    {
       
       if(sea<(root->data))
        {
            cout<<sea<<" "<<root->data<<endl;
        }
        else
        {
            cout<<root->data<<" "<<sea<<endl;
        }
      root->data=INT_MAX;
    }
    
    printNodesSumToSee(root->right,s,temp);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
	printNodesSumToSee(root,s,root);
}
