#ifndef __stack_enhanced__
#define __stack_enhanced__

#include <cassert>
#include <vector>

template <typename T>
class StackEnhanced {
protected:
    std::vector<T> _storage;
    int _head;

public:
    // Initialize a stack with the specified capacity
    StackEnhanced(size_t capacity) : _storage(capacity), _head(0) {}


    // Access the value at the top of the stack
    T& top() { 
        assert(_head > 0) ; 
        return _storage[_head-1]; 
    }

    // Const-access the value at the top of the stack
    const T& top() const { 
        assert(_head > 0) ; 
        return _storage[_head-1]; 
    }

    // Copy a value to the top of the stack
    void push(const T& x) {
        assert(_head < _storage.size());
        _storage[_head++] = x;
    }

    // Move a value to the top of the stack (optional)
    void push(T&& x) {
        assert(_head < _storage.size());
        _storage[_head++] = std::move(x);
    }

    // Pop the value at the top of the stack
    void pop(){
        assert(_head >= 1);
        --_head;
        // prefix decrement returns reference, while postfix returns value
    }

    // Check if the stack is empty
    bool empty() const { return _head == 0; }

    // Check if the stack is full
    bool full() const { return _head == _storage.size(); }


    // ! changes below

    // clear
    void clear(){
        while (_head != 0){
            pop();
        }
    }

    // operator << overloading
    StackEnhanced & operator<<(const T & x){
        // ! if no &, will return a copy, which doesn't work anymore?
        push(x);
        return *this;
    }
};



#endif  // __stack_enhanced__