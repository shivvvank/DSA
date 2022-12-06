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
   void Inorder(TreeNode* root,vector<int> &v)
    {
        if(!root)
            return;
        Inorder(root->left,v);
        v.push_back(root->val);
        Inorder(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        Inorder(root1,v1);
        Inorder(root2,v2);
        cout<<v1.size()<<endl;
        cout<<v2.size()<<endl;
        vector<int> v3;
        int i = 0,j=0;
        while(i<v1.size()&&j<v2.size());
        {
            if(v1[i]<=v2[j])
            {
                v3.push_back(v1[i]);
                i++;
            }
            else
            {
                v3.push_back(v2[j]);
                j++;
            }
        }
        while(i<v1.size())
        {
            v3.push_back(v1[i]);
            i++;
        }
        while(j<v2.size())
        {
            v3.push_back(v2[j]);
        }
        return v3;
    }
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->left->right=new TreeNode(7);
    
    return 0;
}