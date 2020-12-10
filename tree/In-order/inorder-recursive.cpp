#include "../../algorithms/precomp.h"

/*
                                      5
                    2                           13
            3               2                       11
                        3       -2                       1

*/

void inorder(TreeNode* node, vector<int>& res)
{
    if (node != nullptr)
    {
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
}

int main(int argc, char* argv[])
{
    TreeNode t1{ 5 }, t2{ 2 }, t3{ 13 }, t4{ 3 }, t5{ 2 }, t6{ 11 }, t7{ 3 }, t8{ -2 }, t9{ 9 }, t10{ 1 };
	t1.left = &t2; t1.right = &t3; t2.left = &t4; t2.right = &t5; t3.right = &t6; t5.left = &t7; t5.right = &t8; t6.right = &t10;
    vector<int> res;
    inorder(&t1, res);
    for (int i = 0; i < res.size(); ++i)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}