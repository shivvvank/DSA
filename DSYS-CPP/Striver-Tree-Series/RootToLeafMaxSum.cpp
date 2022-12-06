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
void sumHelper(TreeNode* root,int sum, int &maxsum)
{
    if(!root)
        return;
    if(!root->left&&!root->right)
    {
        sum+=root->val;
        maxsum=min(maxsum,sum);
        return;
    }
    sum+=root->val;
    if(root->left)
        sumHelper(root->left,sum,maxsum);
    if(root->right)
        sumHelper(root->right,sum,maxsum);
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->left->right=new TreeNode(7);
    int maxsum=INT_MAX;
    sumHelper(root,0,maxsum);
    cout<<maxsum<<endl;
    return 0;
}