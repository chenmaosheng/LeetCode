## Solution

The idea is to consider an array as a max heap. Max heap means parent is bigger than left child and right child.
How to adjust one node to right place?
1, Choose a node
2, choose a bigger child
3, If child is bigger than node, then swap child and node, and check this child node from 1 - 3
4, If child is smaller than node, means this node as root is a max heap

1, Intial array to a binary tree from root and level by level
2, from last 2 level to root, adjust each node one by one, make the whole heap a max heap
3, Now the root is the biggest number, then swap root and last element of array, now the last element is the biggest element, but heap is not a max heap, then adjust root node (exclude the last node)
4, Loop
5, finish