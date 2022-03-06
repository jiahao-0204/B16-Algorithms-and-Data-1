#ifndef __dequeue__
#define __dequeue__

#include <cassert>
#include <vector>

template <typename T>
class Dequeue
{
protected:
    std::vector<T> _storage;
    size_t _position;
    size_t _size;

public:
    // Create a queue with the specified capacity
    Dequeue(size_t capacity) : _storage(capacity) { 
        assert(capacity > 0); 
        _position = 0;
        _size = 0;
    };

    // Access the element at the front of the queue
    T& front() { return _storage[_head()]; }
    // Const-access the element at the front of the queue
    const T& front() const { return _storage[_head()]; }

    // Copy an element at the back of the queue
    void enqueue(const T& value) { _enqueue(value); }

    // Move an element at the back of the queue
    void enqueue(T&& value) { _enqueue(std::move(value)); }

    // Remove the element at the front of the queue
    void dequeue()
    {
        assert(_size >= 1);
        _size--;
    }

    // Check if the queue is empty
    bool empty() const { return _size == 0; }

    // Check if the queue is full
    bool full() const { return _size == _storage.size(); }



    // ! changes here
    
    // position stores position for the next enqueue

    void clear(){
        _size = 0;
    }

    void enqueue_front(const T& value) {
        // todo : does no check for overwrting! 
        _size++;
        _storage[_head()] = value;
    }

    void dequeue_front() {
        _position++;
        _size--;
        
        if (_position == _storage.size()){
            _position = 0;
        }
    }

    T& back() {
        return _storage[_tail()]; 
    }



private:
    // Enqueue by copying or moving
    template <typename Q>
    void _enqueue(Q&& x)
    {
        assert(_size < _storage.size());
        _storage[_position] = std::forward<Q>(x);
        _size++;
        if (_position == 0) {
            _position = _storage.size() - 1;
        } else {
            _position--;
        }
    }

protected:
    // Return the index of the element to the front of the queue.
    size_t _head() const
    {
        assert(_size >= 1);
        auto index = _position + _size;
        if (index >= _storage.size()) {
            index -= _storage.size();
        }
        return index;
    }

    size_t _tail() const 
    {
        auto index = _position + 1;
        if (index == _storage.size()){
            index = 0;
        }
        return index;
    }

};

#endif  // __dequeue__