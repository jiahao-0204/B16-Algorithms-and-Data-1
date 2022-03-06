/**
 * 
 * ? 1.6 Binary trees
 * 
 * ? 1.6.1 Enhanced BinaryTree class
 * ? Starting from the class BinaryTree given in the notes, write an enhanced 
 * ? binary tree class with a member function parent() returning the parent 
 * ? of a node. Use the following test driver to test it.
 * 
 * ? 1.6.2 Minimum and maximum element in a binary search tree
 * ? Write a module binary_tree_search_enhanced.hpp defining functions bst_min 
 * ? and bst_max com- puting the minimum and maximum element in a BST so that 
 * ? the following test driver works.
 * 
 * ? 1.6.3 Traversing the nodes of a BST by non-decreasing value
 * ? Sketch an algorithm to traverse the nodes of a BST by non-decreasing value.
 * 
 * non-decreasing order -> incresing order
 * 
 * Post-order 
 * left first, then right then parent, 
 * 
 * DFTraversal(T):
 * 1. IF empty(T): Return
 * 2. Let L <- left(T)
 * 3. Let R <- right(T)
 * 4. DFTraversal(L)
 * 5. DFTraversal(R)
 * 6. OutputValue(T)
 * 
 * 
 * 
 * In-order
 * left first, then parent then right
 * 
 * Pre-order
 * parent first, then left, then right
 */

#include "codes/binary_tree_enhanced.hpp"
#include "codes/binary_search_tree_enhanced.hpp"