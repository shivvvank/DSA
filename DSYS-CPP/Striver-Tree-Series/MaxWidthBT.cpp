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
int maxWidth(TreeNode* root)
{
    int maxx=-1;
    queue<pair<TreeNode*,int>> q; // node, Id
    q.push({root,0});
    while(!q.empty())
    {
        int size=q.size();
        int first,last;
        int morder=q.front().second;
        for(int i=0;i<size;i++)
        {
            long long cur_id=q.front().second - morder;
            TreeNode* node= q.front().first;
            q.pop();
            if(i==0)
                first = cur_id;
            if(i==size-1)
                last=cur_id;
            if(node->left)
                q.push({node->left,cur_id*2+1});
            if(node->right)
                q.push({node->right,cur_id*2+2});
        }
        maxx=max(maxx,last-first+1);
    }
    return maxx;
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->left->right=new TreeNode(7);
    cout<<maxWidth(root)<<endl;
    return 0;
}