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
void pathHelper(TreeNode* root,string s,vector<string> &v)
{
    if(!root)
        return;
    if(!root->left&&!root->right)
    {
        s+=to_string(root->val);
        v.push_back(s);
        return;
    }
    s+=to_string(root->val);
    s+="->";
    pathHelper(root->left,s,v);
    pathHelper(root->right,s,v);
}
vector<string> allPaths(TreeNode* root)
{
    vector<string> v;
    pathHelper(root,"",v);
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
    vector<string> v = allPaths(root);
    for(auto i:v)
    {
        cout<<i<<endl;
    }
    return 0;
}