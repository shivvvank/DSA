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
TreeNode* insertBST(TreeNode* root,int val)
{
  if(!root)
    return new TreeNode(val);
  if(root->val>val)
    root->left=insertBST(root->left,val);
  else
    root->right=insertBST(root->right,val);
  return root;
}
int ceilBST(TreeNode* root,int k)
{
  int ceil = -1;
  while(root)
  {
    if(root->val==k)
    {
      ceil=k;
      return ceil;
    }
    else if(root->val<k)
      root=root->right;
    else 
    {
      ceil = root->val;
      root=root->left;
    }
  }
  return ceil;
}
int main()
{
    TreeNode* root=insertBST(nullptr,5);
    root=insertBST(root,7);
    root=insertBST(root,2);
    root=insertBST(root,0);
    root=insertBST(root,3);
    root=insertBST(root,4); 
    printTree(root);
    cout<<ceilBST(root,1)<<endl;
    return 0;
}