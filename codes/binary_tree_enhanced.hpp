#ifndef __binary_tree_enhanced__
#define __binary_tree_enhanced__

#include <memory>
#include <utility>

// A class representing a basic binary tree
// ! struct member has public access by default, class has private access
template <typename V>
struct BinaryTreeEnhanced {
    V _value;
    std::unique_ptr<BinaryTreeEnhanced<V>> _left;
    std::unique_ptr<BinaryTreeEnhanced<V>> _right;
    BinaryTreeEnhanced * _parent = nullptr;

    V& value() { return _value; } // ! return a reference such that we can change the value by tree.value() = 3;
    const V& value() const { return _value; } // ! provide a const return value as well

    BinaryTreeEnhanced<V>* left() const { return _left.get(); } // ? return a const pointer, why?
    BinaryTreeEnhanced<V>* right() const { return _right.get(); }

    BinaryTreeEnhanced<V>* parent() const { return _parent; } 

};


// ! separate data structure and its function, so less memory required
// A helper function to build a binary tree
template <typename V>
std::unique_ptr<BinaryTreeEnhanced<V>> make_binary_tree_enhanced(
                const V& value,
                std::unique_ptr<BinaryTreeEnhanced<V>> left,
                std::unique_ptr<BinaryTreeEnhanced<V>> right
                )
{
    BinaryTreeEnhanced<V> * new_tree_pointer = new BinaryTreeEnhanced<V>{value, std::move(left), std::move(right)};

    // ! changes here
    if (new_tree_pointer->left()) {
        new_tree_pointer->left()->_parent = new_tree_pointer;
    }

    if (new_tree_pointer->right()) {
        new_tree_pointer->right()->_parent = new_tree_pointer;
    }

    return std::unique_ptr<BinaryTreeEnhanced<V>> { new_tree_pointer };
}






#endif  // __binary_tree_enhanced__