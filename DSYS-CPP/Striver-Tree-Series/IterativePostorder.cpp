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
vector<int> iterativePostorder(TreeNode* root)
{
    stack<TreeNode*> s1;
    vector<int> v;
    s1.push(root);
    while(!s1.empty())
    {
        TreeNode* temp = s1.top();
        s1.pop();
        v.push_back(temp->val);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }
    reverse(v.begin(),v.end());
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
    vector<int> v = iterativePostorder(root);
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}