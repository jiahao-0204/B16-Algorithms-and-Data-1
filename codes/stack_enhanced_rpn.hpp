#ifndef __stack_enhanced_rpn__
#define __stack_enhanced_rpn__

// plus, minus, multiplies, divides and negate

#include "stack_enhanced.hpp"


// all assumes operator + - * / exists for type T


template <typename T>
StackEnhanced<T> & plus(StackEnhanced<T> & s){
    T a = s.top(); s.pop();

    T b = s.top(); s.pop();

    s.push(a+b);

    return s;
};


template <typename T>
StackEnhanced<T> & minus(StackEnhanced<T> & s){
    T a = s.top(); s.pop();

    T b = s.top(); s.pop();

    s.push(b-a);

    return s;
};



template <typename T>
StackEnhanced<T> & multiplies(StackEnhanced<T> & s){
    T a = s.top(); s.pop();

    T b = s.top(); s.pop();

    s.push(a*b);

    return s;
};



template <typename T>
StackEnhanced<T> & negate(StackEnhanced<T> & s){
    T a = s.top(); s.pop();

    s.push(-a);

    return s;
};


// ! to implement overload of operator<<, can use function pointer


#endif // __stack_enhanced_rpn__
