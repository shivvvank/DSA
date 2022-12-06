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
void leftViewHelper(TreeNode* root,int level, map<int,int> &m)
{
    if(!root)
        return;
    if(m.find(level)==m.end())
    {
        m.insert({level,root->val});
    }
    leftViewHelper(root->right,level+1,m);
    leftViewHelper(root->left,level+1,m);
}
vector<int> LeftView(TreeNode* root)
{
    map<int,int> m;
    leftViewHelper(root,0,m);
    vector<int> v;
    for(auto i:m)
    {
        v.push_back(i.second);
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
    vector<int> v = LeftView(root);
    for(auto i : v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}