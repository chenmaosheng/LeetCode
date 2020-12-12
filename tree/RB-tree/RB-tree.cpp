#include "../../algorithms/precomp.h"

enum { BLACK, RED };

struct RBNode
{
	int val;
	RBNode* left;
	RBNode* right;
	RBNode* parent;
	int color;

	RBNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}
};


void preorder(RBNode* node, vector<RBNode*>& res)
{
	if (node != nullptr)
	{
		res.push_back(node);
		preorder(node->left, res);
		preorder(node->right, res);
	}
}

void rb_print(RBNode* node)
{
	vector<RBNode*> res;
	preorder(node, res);
	for (int i = 0; i < res.size(); ++i)
	{
		printf("%d %s:", res[i]->val, res[i]->color == RED ? "R" : "B");
	}
	printf("\n\n");
}

void rb_left_rotate(RBNode*& root, RBNode* node)
{
	// node is the rotate point
	RBNode* y = node->right;
	// step 1: right child is right child's left child
	node->right = y->left;
	// step 2: right child's left child's parent is node
	if (y->left)
		y->left->parent = node;
	// step 3: right child's parent is node's parent
	y->parent = node->parent;
	// step 4: parent left or right child is right child
	if (node == root)
		root = y;
	else if (node == node->parent->left)
		node->parent->left = y;
	else
		node->parent->right = y;
	// step 5: right child's left child is node
	y->left = node;
	// step 6: parent is right child
	node->parent = y;
}

void rb_right_rotate(RBNode*& root, RBNode* node)
{
	RBNode* y = node->left;
	// step 1: left child is left child's right child
	node->left = y->right;
	// step 2: left child's right child's parent is node
	if (y->right)
		y->right->parent = node;
	// step 3: left child's parent is node's parent
	y->parent = node->parent;
	// step 4: parent left or right child is left child
	if (root == node)
		root = y;
	else if (node->parent->left == node)
		node->parent->left = y;
	else
		node->parent->right = y;
	// step 5: lfet child's right child is node
	y->right = node;
	// step 6: parent is left child
	node->parent = y;
}

RBNode* rb_bst_insert(RBNode*& root, RBNode* node)
{
	if (root == nullptr)
	{
		root = node;
	}
	else
	{
		if (root->val > node->val)
		{
			root->left = rb_bst_insert(root->left, node);
			root->left->parent = root;
		}
		else
		{
			root->right = rb_bst_insert(root->right, node);
			root->right->parent = root;
		}
	}
	return root;
}

void rb_insert(RBNode*& root, int val)
{
	RBNode* new_node = new RBNode(val);
	root = rb_bst_insert(root, new_node);

	while (new_node != root &&				// case 1: new node is root
		new_node->parent->color == RED)		// case 2: new node's parent is RED
	{
		// case 3.1 new node's parent is left child of grandparent
		if (new_node->parent == new_node->parent->parent->left)
		{
			RBNode* uncle = new_node->parent->parent->right;
			// case 3.1.1 new node's uncle is RED
			if (uncle && uncle->color == RED)
			{
				new_node->parent->color = BLACK;
				uncle->color = BLACK;
				new_node->parent->parent->color = RED;
				new_node = new_node->parent->parent;	// repeat
			}
			// case 3.1.2 new node's uncle is BLACK or no uncle
			else
			{
				// case 3.1.2.1 new node is left child of parent, do a right rotate on parent node
				// case 3.1.2.2 new node is right child of parent, do a left rotate on parent node, and then a right rotate on grandparent node
				if (new_node == new_node->parent->right)
				{
					new_node = new_node->parent;
					rb_left_rotate(root, new_node);
				}
				new_node->parent->color = BLACK;
				new_node->parent->parent->color = RED;
				rb_right_rotate(root, new_node->parent->parent);
			}
		}
		// case 3.2 new node's parent is right child of grandparent
		else
		{
			RBNode* uncle = new_node->parent->parent->left;
			// case 3.2.1 new node's uncle is RED
			if (uncle && uncle->color == RED)
			{
				new_node->parent->color = BLACK;
				uncle->color = BLACK;
				new_node->parent->parent->color = RED;
				new_node = new_node->parent->parent;
			}
			else
			{
				// case 3.2.2.1 new node is right child of parent, do a left rotate on parent node
				// case 3.2.2.2 new node is left child of parent, do a right rotate on parent code and then a left rotate on grandparent node
				if (new_node == new_node->parent->left)
				{
					new_node = new_node->parent;
					rb_right_rotate(root, new_node);
				}
				new_node->parent->color = BLACK;
				new_node->parent->parent->color = RED;
				rb_left_rotate(root, new_node->parent->parent);
			}
		}
	}

	root->color = BLACK;
	rb_print(root);
}


int main(int argc, char* argv[])
{
    RBNode* root = nullptr;
	rb_insert(root, 40);
	rb_insert(root, 30);
	rb_insert(root, 25);
	rb_insert(root, 70);
	rb_insert(root, 80);
	rb_insert(root, 55);
	rb_insert(root, 45);
	rb_insert(root, 46);
	rb_insert(root, 42);
    return 0;
}
