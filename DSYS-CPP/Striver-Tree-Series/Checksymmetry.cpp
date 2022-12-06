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
bool checkSymmetry(TreeNode* root1,TreeNode* root2)
{
  if(!root1&&!root2)
    return true;
  if(!root1||!root2)
    return false;
  if(root1->val!=root2->val)
    return false;
  return checkSymmetry(root1->left,root2->right)&&checkSymmetry(root1->right,root2->left);
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->left->right=new TreeNode(7);
    TreeNode* root1= root;
    TreeNode* root2= new TreeNode(1);
    root2->right=new TreeNode(2);
    root2->left=new TreeNode(3);
    root2->right->right=new TreeNode(4);
    root2->right->left=new TreeNode(7);
    if(checkSymmetry(root1,root2))
    {
      cout<<"Symmetrical!"<<endl;
    }
    else
      cout<<"Not Symmetrical!"<<endl;
    return 0;
}