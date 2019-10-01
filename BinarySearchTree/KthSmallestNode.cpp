#include<bits/stdc++.h>

int findNode(BinaryTreeNode<int>* root, int k) {
    vector<BinaryTreeNode<int>*> stack;
    while(true)
    {
        while(root!=NULL)
        {
            stack.push_back(root);
            root=root->left;
        }
        root=stack.back();
        stack.pop_back();
        if(--k==0)return root->data;
        root=root->right;
	}
}
