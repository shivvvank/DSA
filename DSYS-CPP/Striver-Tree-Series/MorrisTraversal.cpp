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
vector<int> MorrisTraversalInorder(TreeNode* root)
{
    vector<int> inorder;
    TreeNode* cur = root;
    while(cur)
    {
        if(!cur->left)
        {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            TreeNode* prev = cur->left;
            while(prev->right&& prev->right!=cur)
                prev=prev->right;
            if(!prev->right)
            {
                prev->right = cur;
                //preorder insert that here
                cur=cur->left;
            }
            else
            {
                prev->right=nullptr;
                inorder.push_back(cur->val); // preorder : remove this
                cur=cur->right;
            }
        }
    }
    return inorder;
    
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->left->right=new TreeNode(7);
    vector<int> v = MorrisTraversalInorder(root);
    for(auto i : v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}