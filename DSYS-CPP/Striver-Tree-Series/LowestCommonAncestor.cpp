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
int LCA(TreeNode* root,int a,int b)
{
    if(!root)
        return -1;
    int templ = LCA(root->left,a,b);
    int tempr = LCA(root->right,a,b);
    if(root->val==a)
        return a;
    else if(root->val==b)
        return b;
    else if((templ==a&&tempr==b)||(templ==b&&tempr==a))
        return root->val;
    else if(templ!=a&&templ!=b&&templ!=-1)
        return templ;
    else if(tempr!=a&&tempr!=b&&tempr!=-1)
        return tempr;
    else 
        return -1;
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->left->right=new TreeNode(7);
    cout<<LCA(root,4,7)<<endl;
    return 0;
}