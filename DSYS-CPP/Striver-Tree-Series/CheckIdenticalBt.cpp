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
bool checkIdentical(TreeNode* root1,TreeNode* root2)
{
    if(root1==nullptr&&root2==nullptr)
        return true;
    else if(root1==nullptr||root2==nullptr)
        return false;
    else
    {
        bool checkleft = checkIdentical(root1->left,root2->left);
        bool checkright = checkIdentical(root1->right,root2->right);
        if(checkleft && checkright &&(root1->val==root2->val))
            return true;
        else
            return false;
    }
}
int main()
{
    TreeNode* root1=new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left=new TreeNode(4);
    root1->right->right=new TreeNode(5);
    root1->left->right=new TreeNode(7);

    TreeNode* root2=new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left=new TreeNode(4);
    root2->right->right=new TreeNode(5);
    //root2->left->right=new TreeNode(7);

    if(checkIdentical(root1,root2))
        cout<<"Identical"<<endl;
    else
        cout<<"Not Identical"<<endl;
    return 0;
}