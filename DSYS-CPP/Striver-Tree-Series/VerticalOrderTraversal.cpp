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
void verticalHelper(TreeNode* root,int width,map<int,unordered_set<int>> &m)
{
    if(!root)
        return;
    if(m.find(width)==m.end())
    {
        m.insert({width,{root->val}});
    }
    else
    {
        m[width].insert(root->val);
    }
    verticalHelper(root->left,width-1,m);
    verticalHelper(root->right,width+1,m);
}
vector<vector<int>> verticalTraversal(TreeNode* root)
{
    map<int,unordered_set<int>> m;
    verticalHelper(root,0,m);
    vector<vector<int>> ans;
    for(auto i:m)
    {
        vector<int> temp;
        for(auto j:i.second)
        {
            temp.push_back(j);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->left->right=new TreeNode(7);
    vector<vector<int>> v = verticalTraversal(root);
    for(int i = 0;i<v.size();i++)
    {
        for(int j = 0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}