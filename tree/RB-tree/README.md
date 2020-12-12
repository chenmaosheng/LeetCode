## Solution

# Red black tree

Red black tree is another balanced tree, but not as balanced as AVL tree. It doesn't care about height difference.

There are 4 rules:

1, Each node must be either black or red.

2, Root node is black

3, If node is red, the left child and right child must be black (means new node's parent must be BLACK)

4, Every path from node to any of its descedent NULL node has the same number of black node (means new node must be RED)

NULL node is BLACK

# Rotate

# Left rotate
     
        p       
       /
      x
     /
   y
  / \
z    k

->
        p
       /
      y
     /  \
    z    z
        /
       k

left rotate means k becomes left of x, and x become right of y, notice x's parent becomes y's parent

# Right rotate

 p
  \
   x
    \    
      y
     / \
    z   k

->

   p
    \
      y
    /  \
   x    k
    \
     z   

right rotate means z becomes right of x, and x become left of y, notice x's parent becomes y's parent

# Insert

There are four situations

1, new node's parent is left of grandparent, parent is RED, uncle is RED, grandparent is BLACK

     B
   /   \
  R    R       
  /
R(new)

     B
   /   \
  R    R
   \
    R(new)

It breaks rule 3. Change parent to BLACK, uncle to BLACK, grandparent to RED. 

Here is a problem. What if grandparent's parent is RED? Consider grandparent as new node, and repeat the flow, until it doesn't break rules

2, mirror of 1

     B
   /   \
  R    R
        \
         R(new)

     B
   /   \
  R     R
       /
      R(new)

3, new node's parent is left child of grandparent, parent is RED, uncle is BLACK, grandparent is BLACK

     B
   /   \
  R     B
   \
    R(new)

if new node is right child of parent like above, need to left rotate parent, let parent becomes new node's left child and

set parent color to BLACK, and grandparent color to RED

     B->R
   /   \
  R->B  B
  / 
 R

 Then can use the same code of new node is left child of parent, right rotate grandparent to this:

     B
    / \
   R   R
        \
         B

4, mirror of 3