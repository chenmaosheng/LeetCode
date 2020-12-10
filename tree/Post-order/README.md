## Solution

# Post-order iterative

1, Post-order starts from the left most node, use stack to save all the left node first (start from root)

2, need to keep a last walk-through right child, otherwise popup a right node will go to next right again

3, Read top node, if this node has no right child or the right child is last right (means this right child already walked), then popup top node and set this node to last right. 

4, If top node has right child, then go to 1