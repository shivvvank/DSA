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
void printLeafDFS(TreeNode* root,vector<int> &v)
{
    if(!root)
        return;
    if(!root->left&&!root->right)
    {
        v.push_back(root->val);
    }
    printLeafDFS(root->left,v);
    printLeafDFS(root->right,v);
}
vector<int> boundaryTraversal(TreeNode* root)
{
    TreeNode* node = root;
    vector<int> v;
    while(true)
    {
        if(node->left|| node->right)
        {
            v.push_back(node->val);
        }
        if(node->left)
        {
            node = node->left;
        }
        else if(node->right)
        {
            node = node->right;
        }
        else
        {
            break;
        }
    }
    printLeafDFS(root,v);
    vector<int> vr ;
    node=root;
    while(true)
    {
        if(node->left||node->right)
            vr.push_back(node->val);
        if(node->right)
            node=node->right;
        else if(node->left)
            node = node->left;
        else
            break;
    }
    for(int i=vr.size()-1;i>0;i--)
    {
        v.push_back(vr[i]);
    }
    return v;
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->left->right=new TreeNode(7);
    vector<int> v = boundaryTraversal(root);
    for(auto i: v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
