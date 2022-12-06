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
vector<int> iterativeInorder(TreeNode* root)
{
    stack<TreeNode*> s;
    vector<int> v;
    TreeNode* node = root;
    while(true)
    {
        if(node!=nullptr)
        {
            s.push(node);
            node = node->left;
        }
        else
        {
            if(s.empty())  
                break;
            node = s.top();
            s.pop();
            v.push_back(node->val);
            node = node->right;    
        }
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
    vector<int> v = iterativeInorder(root);
    for(auto i : v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}