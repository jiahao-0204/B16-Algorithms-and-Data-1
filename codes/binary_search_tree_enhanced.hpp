#ifndef __binary_search_tree_enhanced__
#define __binary_search_tree_enhanced__

#include "binary_tree.hpp"


/**
 * binary tree
 *  |-> binary search tree 
 *  |-> heap
 * 
 * binary search tree and heap are types of binary tree
 * 
 * 
 * ! binary tree has two children which are also binary tree
 * 
 * ! binary search tree has left children all smaller than current value and right children all larger than current value
 * 
 * ! heap is when all children are all larger or all smaller than current value
 * 
 */

template <typename V>
std::unique_ptr<BinaryTree<V>> bst_insert(std::unique_ptr<BinaryTree<V>> tree, const V& value)
{
    if (!tree) return make_binary_tree(value, {}, {});
    if (value <= tree->value()) {
        tree->_left = bst_insert(std::move(tree->_left), value);
    } else {
        tree->_right = bst_insert(std::move(tree->_right), value);
    }
    return tree;
}


// ! this function works for any struct that has value(), left() and right() defined
template <class T, typename V>
T bst_search(const T& tree, const V& value)
{
    if (!tree || value == tree->value()) return tree;
    if (value < tree->value()) return bst_search(tree->left(), value);
    auto other = bst_search(tree->right(), value);
    return other ? other : tree;
}


// ! changes here
template <class T>
T* bst_min(T* tree)
{
    // assuming tree is not null
    if (tree->left()) return bst_min(tree->left());
    return tree;
}

template <class T>
T* bst_max(T* tree)
{
    // assuming tree is not null
    if (tree->right()) return bst_max(tree->right());
    return tree;
}

#endif  // __binary_search_tree_enhanced__
