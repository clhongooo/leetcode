#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    void foreTraverse(TreeNode* root, vector<TreeNode*>& vec)
    {
        if(root == NULL)
        {
            return;
        }
        foreTraverse(root->left, vec);
        vec.push_back(root);
        foreTraverse(root->right, vec);
    }