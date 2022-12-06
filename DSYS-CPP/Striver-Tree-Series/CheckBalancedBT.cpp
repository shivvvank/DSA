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
int CheckBalance(TreeNode* root)
{
    if(root==nullptr)
        return true;
    else
    {
        int lb = CheckBalance(root->left);
        int rb = CheckBalance(root->right);
        if(lb != rb)
            return -1;
        if(lb == -1 || rb ==-1)
            return -1;
        return 1+max(lb,rb);  
    }
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    //root->left->left=new TreeNode(4);
    //root->right->right=new TreeNode(5);
    //root->left->right=new TreeNode(7);
    if(CheckBalance(root)==-1)
        cout<<"Tree is not balanced."<<endl;
    else
        cout<<"Tree is balanced."<<endl;
    return 0;
}

/*
        1
    2      3
4      7      5
    

*/