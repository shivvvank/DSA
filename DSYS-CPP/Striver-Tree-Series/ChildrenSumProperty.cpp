#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
  int val ; 
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val)
  {
    this->val= val;
    this->left=nullptr;
    this->right=nullptr;
  }
  TreeNode(int val,TreeNode* left, TreeNode* right)
  {
    this->val = val;
    this->left=left;
    this->right = right;
  }
};
void ChildrenSumProp(TreeNode* root)
{
    if(!root)
        return;
    ChildrenSumProp(root->left);
    ChildrenSumProp(root->right);
    int childsum = 0;
    if(root->left)
        childsum+=root->left->val;
    if(root->right)
        childsum+=root->right->val;
    if(childsum>=root->val)
        root->val = childsum;
    else
    {
        if(root->left)
            root->left->val=root->val;
        if(root->right)
            root->right->val=root->val;
    }
}
    void printTree(TreeNode* root)
    {
        if(root==nullptr)
            return;
        else
        {
            cout<<"root : "<<root->val;
            if(root->left)
                cout<<", left : "<<root->left->val;
            if(root->right)
                cout<<", right : "<<root->right->val;
            cout<<endl;
            printTree(root->left);
            printTree(root->right);
        }
    }
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->left->right=new TreeNode(7);
    printTree(root);
    ChildrenSumProp(root);
    printTree(root);
    return 0;
}
