#ifndef __list_enhanced__
#define __list_enhanced__

#include <cassert>
#include <vector>
#include <memory>



template <typename T>
struct Node {
    T value;
    std::unique_ptr< Node<T> > next;

    Node() : value{}, next(nullptr) {}
    Node(const T& value, std::unique_ptr< Node<T> > next)
        : value(value), next(std::move(next))
    {
    }
};

template <typename T>
Node<T>* list_insert_after(Node<T>* node, const T& value)
{
    node->next =
        std::make_unique< Node<T> >(value, std::move(node->next));
    return node->next.get();
}


template <typename T>
Node<T>* list_delete_after(Node<T>* node)
{
    std::unique_ptr< Node<T> > next_node = std::move(node->next);
    
    node->next = std::move(next_node->next);
    
    // ! since next_node is not passed outwards by return, once this function 
    // ! is exited, the unique_ptr will go out off scope, and the content in the 
    // ! pointer will be deleted. 

    // ! to explicitly delete the content in the next_node pointer, use reset

    next_node.reset();

    return node->next.get();
}










template <typename T, typename F>
Node<T>* list_find_predecessor(Node<T>* node, F predicate)
{
    for (; node && node->next; node = node->next.get()) {
        if (predicate(node->next->value)) return node;
    }
    return nullptr;
}

template <typename T>
std::vector<T> list_to_vector(const Node<T>& node)
{
    std::vector<T> v;
    for (Node<T>* current = node.next.get(); current;
         current = current->next.get()) {
        v.push_back(current->value);
    }
    return v;
}

#endif  // __list_enhanced__
