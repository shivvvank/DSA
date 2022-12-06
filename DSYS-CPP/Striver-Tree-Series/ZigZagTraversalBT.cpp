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
void swapf(int& flag)
{
    if(flag==0)
        flag=1;
    else
        flag=0;
}
vector<vector<int>> zigzag(TreeNode* root)
{
    queue<TreeNode*> q;
    vector<vector<int>> bfs;
    if(root==nullptr)
        return bfs;

    q.push(root);
    int flag=0;
    while(!q.empty())
    {
        int num = q.size();
        vector<int> tempans;
        for(int i=0;i<num;i++)
        {
            TreeNode* temp = q.front();
            q.pop();
            tempans.push_back(temp->val);
            if(temp->left !=nullptr)
                q.push(temp->left);
            if(temp->right!=nullptr)
                q.push(temp->right);
        }
        if(flag==0)
            bfs.push_back(tempans);
        else
        {
            reverse(tempans.begin(),tempans.end());
            bfs.push_back(tempans);
        }
        swapf(flag);
    }
    return bfs;
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(6);
    root->left->right=new TreeNode(5);
    vector<vector<int>> zz = zigzag(root);
    for(auto i: zz)
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}