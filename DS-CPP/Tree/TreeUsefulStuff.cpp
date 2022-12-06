    void printTree(TreeNode* root)
    {
        if(root==nullptr)
            return;
        else
        {
            cout<<"root : "<<root->val;
            if(root->left)
                cout<<", left : "<<root->left->val;
            if(root->right)
                cout<<", right : "<<root->right->val;
            cout<<endl;
            printTree(root->left);
            printTree(root->right);
        }
    }