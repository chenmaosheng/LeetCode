#include "../../algorithms/precomp.h"

struct AVLNode
{
	AVLNode* left;
	AVLNode* right;
	int val;
	int height;
	AVLNode(int x) : val(x), left(NULL), right(NULL), height(1) {}
};

int avl_height(AVLNode* node)
{
    return node == nullptr ? 0 : node->height;
}

int avl_balance(AVLNode* node)
{
    if (node == nullptr) return 0;
    return avl_height(node->left) - avl_height(node->right);
}

AVLNode* avl_min_node(AVLNode* node)
{
    while (node && node->left)
    {
        node = node->left;
    }
    return node;
}

AVLNode* avl_left_rotate(AVLNode* node)
{
    AVLNode* tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;

    node->height = max(avl_height(node->left), avl_height(node->right))+1;
    tmp->height = max(avl_height(tmp->left), avl_height(tmp->right))+1;
    return tmp;
}

AVLNode* avl_right_rotate(AVLNode* node)
{
    AVLNode* tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;

    node->height = max(avl_height(node->left), avl_height(node->right))+1;
    tmp->height = max(avl_height(tmp->left), avl_height(tmp->right))+1;
    return tmp;
}

AVLNode* avl_left_right_rotate(AVLNode* node)
{
    node->left = avl_left_rotate(node);
    return avl_right_rotate(node);
}

AVLNode* avl_right_left_rotate(AVLNode* node)
{
    node->right = avl_right_rotate(node);
    return avl_left_rotate(node);
}

AVLNode* avl_insert(AVLNode* node, int val)
{
    if (node == nullptr) return new AVLNode(val);
    if (node->val > val)
    {
        node->left = avl_insert(node->left, val);
    }
    else if (node->val < val)
    {
        node->right = avl_insert(node->right, val);
    }

    node->height = max(avl_height(node->left), avl_height(node->right))+1;
    int balance = avl_balance(node);
    if (balance > 1)
    {
        // left left case
        if (node->left->val > val)
        {
            node = avl_right_rotate(node);
        }
        // left right case
        else if (node->left->val < val)
        {
            node = avl_left_right_rotate(node);
        }
    }
    else if (balance < -1)
    {
        // right right case
        if (node->right->val < val)
        {
            node = avl_left_rotate(node);
        }
        // right left case
        else if (node->right->val > val)
        {
            node = avl_right_left_rotate(node);
        }
    }
    return node;
}

AVLNode* avl_delete(AVLNode* node, int val)
{
    if (node == nullptr) return node;
    if (node->val > val)
    {
        node->left = avl_delete(node->left, val);
    }
    else if (node->val < val)
    {
        node->right = avl_delete(node->right, val);
    }
    else
    {
        if (node->left && node->right)
        {
            AVLNode* tmp = avl_min_node(node->right);
            node->val = tmp->val;
            node->right = avl_delete(node->right, tmp->val);
        }
        else
        {
            node = node->left ? node->left : node->right;
        }
    }
    if (node == nullptr) return node;

    node->height = max(avl_height(node->left), avl_height(node->right))+1;
    int balance = avl_balance(node);
    int left_balance = avl_balance(node->left), right_balance = avl_balance(node->right);

    if (balance > 1)
    {
        // left left case
        if (left_balance >= 0)
        {
            node = avl_right_rotate(node);
        }
        else
        {
            node = avl_left_right_rotate(node);
        }
    }
    else if (balance < -1)
    {
        // right right case
        if (right_balance <= 0)
        {
            node = avl_left_rotate(node);
        }
        else
        {
            node = avl_right_left_rotate(node);
        }
    }
    return node;
}


void preorder(AVLNode* node, vector<int>& res)
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
    AVLNode t1{ 60 };
	AVLNode* ins = avl_insert(&t1, 40);
	ins = avl_insert(ins, 30);
	ins = avl_insert(ins, 25);
	ins = avl_insert(ins, 70);
	ins = avl_insert(ins, 80);
	ins = avl_insert(ins, 55);
	ins = avl_insert(ins, 45);
	ins = avl_insert(ins, 46);
	ins = avl_delete(ins, 25);
	ins = avl_delete(ins, 55);
	ins = avl_insert(ins, 42);
	ins = avl_delete(ins, 70);
	vector<int> res;
	preorder(ins, res);
	for (int i = 0; i < res.size(); ++i)
	{
		printf("%d ", res[i]);
	}
    return 0;
}