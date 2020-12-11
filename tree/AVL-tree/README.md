## Solution

# AVL

AVL tree improves BST tree, BST tree may degrade to a linked list, AVL guarantees left and right diff is no more than 1.
It is a balanced binary tree.

# Left rotate

       x
   y
z    k

->

      y
    z     z
        k

left rotate means k becomes left of x, and x become right of y

# Right rotate

   x
        y
      z   k

->

      y
  x
    z   k

right rotate means z becomes right of x, and x become left of y

# Case 1: left left

Left height - right height is 2. And y is left child of z and x is left child of y

Use right rotate on z in this case

# Case 2: left right

Left height - right height is 2. And y is left child of z and x is right child of y

Use left rotate on y, and use right rotate on z in this case

# Case 3: right right

Right height - left right is 2. And y is right child of z and x is right child of y

Use left rotate on z in this case

# Case 4: right left

Right height - left right is 2. And y is right child of z and x is left child of y

Use right rotate on y, and use left rotate on z in this case

# AVL insert

similar to BST tree, first insert new value to a right place, and update the height in each node walked through

Then check the balance (left height - right height), if more than 1, there are two cases:

1, left left case when left node value > insert value

2, left right case when left node value < insert value

If less than -1, there are two cases as well:

1, right right case when right node value < insert value

2, right left case when right node value > insert value

# AVL delete

similar to BST tree, first delete value from existing tree, and update the height in each node walked through

there are two possibilities:

1, node has 0 or 1 child

if child is left only, then replace with left, if child is right only, then replace with right, if 0 child, replace with nullptr

2, node has 2 children

Go to right subtree and find the minimal value in right subtree, use it to replace node. And next step is to remove the minimal value node. Then go to right subtree and delete this minimal value

Then check the balance (left height - right height), if more than 1, there are two cases:

1, left left case when left node balance >= 0 (left node has left child)

2, left right case when left node balance < 0 (left node has right child only)

If less than -1, there are two cases as well:

1, right right case when right node balance < 0 (right node has right child only)

2, right left case when right node balance >= 0 (right node has left child)
