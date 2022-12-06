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

int maxPath(TreeNode* root,int& maxx)
{
    if(root==nullptr)
        return 0;
    else
    {
        int lh = maxPath(root->left,maxx);
        int rh = maxPath(root->right,maxx);
        maxx = max(maxx,lh+rh+(root->val));
        return max(lh,rh)+ root->val;
    }
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->left->left->right=new TreeNode(7);
    int maxx=-1;
    maxPath(root,maxx);
    cout<<"Max Path Sum = "<<maxx<<endl;
    return 0;
}