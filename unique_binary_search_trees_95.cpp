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

vector<TreeNode*> CreateTree(int start, int end)
{
    vector<TreeNode*> result_vec;
    if(start < end)
    {
        result_vec.push_back(NULL);
        return result_vec;
    }

    for(int i = start; i <= end; i++)
    {
        vector<TreeNode*> left = CreateTree(start, i - 1);
        vector<TreeNode*> right = CreateTree(i+1, end);
        for(int k = 0; k < left.size(); k++)
        {
            for(int t = 0; t < right.size(); t++)
            {
                TreeNode* node = new TreeNode(i);
                node->left = left[k];
                node->right = right[t];
                result_vec.push_back(node);
            }
        }
    }
    
    return result_vec;    
}

vector<TreeNode*> generateTrees(int n)
{
    return CreateTree(1, n);
}

int main()
{
    return 0;
}