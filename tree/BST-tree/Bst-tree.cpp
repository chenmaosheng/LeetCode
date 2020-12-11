#include "../../algorithms/precomp.h"

TreeNode* bst_insert(TreeNode* node, int val)
{
    if (node == nullptr) return new TreeNode(val);
    if (node->val > val)
    {
        node->left = bst_insert(node->left, val);
    }
    else
    {
        node->right = bst_insert(node->right, val);
    }
    return node;
}

TreeNode* bst_search(TreeNode* node, int val)
{
    if (node == nullptr || node->val == val) return node;
    if (node->val > val)
    {
        return bst_search(node->left, val);
    }
    return bst_search(node->right, val);
}

TreeNode* bst_minnode(TreeNode* node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

/*
1, node has one or 0 child
2, node has two children
*/
TreeNode* bst_delete(TreeNode* node, int val)
{
    if (node == nullptr) return node;
    if (node->val > val)
    {
        node->left = bst_delete(node->left, val);
        return node;
    }
    else if (node->val < val)
    {
        node->right = bst_delete(node->right, val);
        return node;
    }
    else
    {
        // one or 0 child
        if (node->left == nullptr)
        {
            return node->right;
        }
        else if (node->right == nullptr)
        {
            return node->left;
        }
        else
        {
            // two children, find minimal val from right and replace node value
            // and go to right side, delete that minival value node
            TreeNode* tmp = bst_minnode(node->right);
            node->val = tmp->val;
            node->right = bst_delete(node->right, tmp->val);
        }
    }
    return node;
}


void preorder(TreeNode* node, vector<int>& res)
{
    if (node != nullptr)
    {
        res.push_back(node->val);
        preorder(node->left, res);
        preorder(node->right, res);
    }
}

int main(int argc, char* argv[])
{
    TreeNode t1{ 60 }, t2{ 40 }, t3{ 70 }, t4{ 30 }, t5{ 50 }, t6{ 55 }, t7{ 80 };
	t1.left = &t2; t1.right = &t3; t2.left = &t4; t2.right = &t5; t3.left = &t6; t3.right = &t7;

    TreeNode* ins = bst_insert(&t1, 35);
    ins = bst_insert(ins, 25);
    ins = bst_delete(ins, 40);
    ins = bst_delete(ins, 60);
    vector<int> res;
    preorder(ins, res);
    for (int i = 0; i < res.size(); ++i)
    {
        printf("%d ", res[i]);
    }
    TreeNode* sea = bst_search(ins, 25);
    if (sea) printf(" %d ", sea->val);
    else printf(" not found \n");
    return 0;
}