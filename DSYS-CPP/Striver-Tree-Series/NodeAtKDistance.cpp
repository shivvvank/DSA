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
void findParentMapping(TreeNode* root,map<TreeNode*,TreeNode*> &parent)
{
    if(!root)
        return;
    if(root->left)
        parent.insert({root->left,root});
    if(root->right)
        parent.insert({root->right,root});
    findParentMapping(root->left,parent);
    findParentMapping(root->right,parent);
}
void findNodesAtK(TreeNode* node,int k,map<TreeNode*,TreeNode*> parent,map<TreeNode*,bool> &vis,vector<int> &v)
{
    if(!node)
        return;
    if(k==0)
    {
        v.push_back(node->val);
        vis[node]=true;
        return;
    }
    vis[node]=true;
    if(node->left&&!vis[node->left])
        findNodesAtK(node->left,k-1,parent,vis,v);
    if(node->right&&!vis[node->right])
        findNodesAtK(node->right,k-1,parent,vis,v);
    if(parent[node] && !vis[parent[node]])
        findNodesAtK(parent[node],k-1,parent,vis,v);
}
vector<int> nodesAtK(TreeNode* root,TreeNode* node,int k)
{
    map<TreeNode*,TreeNode*> parent;
    findParentMapping(root,parent);
    TreeNode* temp = node;
    vector<int> v ;
    map<TreeNode*,bool> vis;
    findNodesAtK(node,k,parent,vis,v);
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
    vector<int> v = nodesAtK(root,root->right->right,5);
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
