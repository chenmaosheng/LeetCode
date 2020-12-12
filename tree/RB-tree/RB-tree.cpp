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

RBNode* rb_right_rotate(RBNode*& root, RBNode* node)
{
	RBNode* parent = node->parent, *grandparent = parent->parent;
	// step 1: parent left child is node right child
	parent->left = node->right;
	// step 2: node right child's parent is parent
	if (node->right)
		node->right->parent = parent;
	// step 3: node parent is grandparent
	node->parent = grandparent;
	// step 4: grandparent left child is node
	if (grandparent == nullptr)
		root = node;
	else if (grandparent->left == parent)
		grandparent->left = node;
	else
		grandparent->right = node;
	// step 5: node right child is parent
	node->right = parent;
	// step 6: parent's parent is node
	parent->parent = node;
	return node;
}

RBNode* rb_left_rotate(RBNode*& root, RBNode* node)
{
	RBNode* parent = node->parent, *grandparent = parent->parent;
	// step 1: parent right child is node left child
	parent->right = node->left;
	// step 2: node left child's parent is parent
	if (node->left)
		node->left->parent = parent;
	// step 3: node parent is grandparent
	node->parent = grandparent;
	// step 4: grandparent left or right child is node
	if (grandparent == nullptr)
		root = node;
	else if (grandparent->left == parent)
		grandparent->left = node;
	else
		grandparent->right = node;
	// step 5: node left child is parent
	node->left = parent;
	// step 6: parent's parent is node
	parent->parent = node;
	
	return node;
}

RBNode* rb_bst_insert(RBNode* node, RBNode* new_node)
{
	if (node == nullptr) return new_node;
	if (node->val > new_node->val)
	{
		node->left = rb_bst_insert(node->left, new_node);
 		node->left->parent = node;
	}
	else if (node->val < new_node->val)
	{
		node->right = rb_bst_insert(node->right, new_node);
		node->right->parent = node;
	}
	return node;
}

void rb_insert(RBNode*& root, int val)
{
	RBNode* new_node = new RBNode(val);
	root = rb_bst_insert(root, new_node);

	// case 1: new node is root
	if (new_node == root)
	{
		root->color = BLACK;
	}
	// case 2: new node's parent is BLACK
	else if (new_node->parent->color == BLACK)
	{
		// do nothing
	}
	else
	{
		// case 3: new node's parent is RED
		while (new_node->parent->color == RED)
		{
			// case 3.1 new node's uncle is RED
			RBNode* parent = new_node->parent, *grandparent = parent->parent;
			// case 3.1.1 new node's parent is left child of grandparent
			if (parent->val < grandparent->val && grandparent->right && grandparent->right->color == RED)
			{
				parent->color = BLACK;
				grandparent->right->color = BLACK;
				grandparent->color = RED;
				// need to continue and set X as grandparent
				if (grandparent->val != root->val)
					new_node = grandparent;
				else
					break;
			}
			// case 3.1.2 new node's parent is right child of grandparent
			else if (parent->val > grandparent->val && grandparent->left && grandparent->left->color == RED)
			{
				parent->color = BLACK;
				grandparent->left->color = BLACK;
				grandparent->color = RED;
				// need to continue and set X as grandparent
				if (grandparent->val != root->val)
					new_node = grandparent;
				else
					break;
			}
			// case 3.2 new node's uncle is BLACK and is right child of grandparent
			else if (parent->val < grandparent->val && (grandparent->right == nullptr || grandparent->right->color == BLACK))
			{
				// case 3.2.1 new node is left child of parent, do a right rotate on parent node
				if (new_node->val < parent->val)
				{
					parent = rb_right_rotate(root, parent);
					parent->color = BLACK;
					parent->right->color = RED;
				}
				// case 3.2.2 new node is right child of parent, do a left rotate on new node, and then a right rotate on new node
				else if (new_node->val > parent->val)
				{
					new_node = rb_left_rotate(root, new_node);
					new_node = rb_right_rotate(root, new_node);
					new_node->color = BLACK;
					new_node->right->color = RED;
				}
				break;
			}
			// case 3.3 new node's uncle is BLACK and is left child of grandparent
			else if (parent->val > grandparent->val && (grandparent->left == nullptr || grandparent->left->color == BLACK))
			{
				// case 3.3.1 new node is right child of parent, do a left rotate on parent node
				if (new_node->val > parent->val)
				{
					parent = rb_left_rotate(root, parent);
					parent->color = BLACK;
					parent->left->color = RED;
				}
				// case 3.3.2 new node is left child of parent, do a right rotate on new node and then a left rotate on new node
				else if (new_node->val < parent->val)
				{
					new_node = rb_right_rotate(root, new_node);
					new_node = rb_left_rotate(root, new_node);
					new_node->color = BLACK;
					new_node->left->color = RED;
				}
				break;
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
