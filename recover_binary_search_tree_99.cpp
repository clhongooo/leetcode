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

void recoverTree(TreeNode* root) 
{
    vector<TreeNode*> result_vec;
    foreTraverse(root, result_vec);
    TreeNode *small = NULL, *big = NULL;
    int vec_size = result_vec.size();
    for(int i = 0; i < vec_size - 1; i++)
    {
        if(result_vec[i]->val > result_vec[i+1]->val)
        {
            big = result_vec[i];
            break;
        }
    }
    for(int i = vec_size - 1; i > 0; i--)
    {
        if(result_vec[i]->val < result_vec[i-1]->val)
        {
            small = result_vec[i];
            break;
        }
    }
    if(small && big)
    {
        int tmp = small->val;
        small->val = big->val;
        big->val = tmp;
    }
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = NULL;
    root->left->left = NULL;
    root->left->right = new TreeNode(2);
    recoverTree(root);
    return 0;
}