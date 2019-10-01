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
int totalCount(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return totalCount(root->left)+totalCount(root->right)+1;
    }
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
   if(root==NULL)
   {
       return;
   }
    int Count=totalCount(root);
   stack<BinaryTreeNode<int>*> inorder;
   stack<BinaryTreeNode<int>*> revorder;
   BinaryTreeNode<int>* top1,*top2;
    BinaryTreeNode<int>* temp=root;
   while(temp!=NULL)
    {
        inorder.push(temp);
        temp=temp->left;
	}
    temp=root;
    while(temp!=NULL)
    {
        revorder.push(temp);
        temp=temp->right;
    }
    int count=0;
    while(count<Count-1)
    {
        top1=inorder.top();
        top2=revorder.top();
        if(top1->data+top2->data==s)
        {
            cout<<top1->data<<" "<<top2->data<<endl;
            count++;
            inorder.pop();
            BinaryTreeNode<int>* top;
            top=top1;
            if(top->right!=NULL)
            {
                top=top->right;
                 while(top!=NULL)
            {
                inorder.push(top);
                top=top->left;
            }
            }
            top=top2;
            revorder.pop();
            count++;
            if(top->left!=NULL)
            {
                top=top->left;
                while(top!=NULL)
                {
                    revorder.push(top);
                    top=top->right;
                }
            }
           
        }
        else if(top1->data+top2->data>s)
        {
            BinaryTreeNode<int>* top=top2;
            count++;
            revorder.pop();
            if(top->left!=NULL)
            {
                top=top->left;
                while(top!=NULL)
                {
                    revorder.push(top);
                    top=top->right;
				}
            }
            
        }
        else
        {
            BinaryTreeNode<int>* top=top1;
            count++;
            inorder.pop();
            if(top->right!=NULL)
            {
                top=top->right;
                while(top!=NULL){
                    inorder.push(top);
                    top=top->left;
                }
            }
        }
    }

}
