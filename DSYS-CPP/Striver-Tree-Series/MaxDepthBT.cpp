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

int maxDepth(TreeNode* root)
{
    if(root==nullptr)
        return 0;
    else
    {
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        return 1+max(ld,rd);
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
    cout<<"MaxDepth : "<<maxDepth(root)<<endl;
    return 0;
}