## Solution

# BST
all nodes left of node are smaller than node, all nodes right of node are bigger than node

# BST insert

if smaller than node, insert to left, otherwise insert to right


# BST search

if equal return result, if smaller than node, search left, otherwise search right

# BST delete

there are two possibilities:

1, node has 0 or 1 child

if child is left only, then replace with left, if child is right only, then replace with right, if 0 child, replace with nullptr

2, node has 2 children

Go to right and find the minimal value in right, use it to replace node. And next step is to remove the minimal value node. Then go to right and delete this minimal value
