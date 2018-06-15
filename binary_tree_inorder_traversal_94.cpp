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

void inorder(TreeNode* root, vector<int>& vec)
{
    if(root->left)
    {
        inorder(root->left, vec);
    }
    vec.push_back(root->val);
    if(root->right)
    {
        inorder(root->right, vec);
    }        
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result_vec;
    if(root == NULL)
    {
        return result_vec;
    }
    
    inorder(root, result_vec);
    return result_vec;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = NULL;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = NULL;
    cout << inorderTraversal(root);
    return 0;
}