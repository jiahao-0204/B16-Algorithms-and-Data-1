/**
 * 
 * ? 1.3 Stacks
 * 
 * ? 1.3.1 Enhanced stack class
 * ? Starting from the class Stack given in the notes, create a new stack class 
 * ? StackEnhanced with a member function clear to remove all elements from the 
 * ? stack. Also write an overload of operator<< so that elements can be pushed 
 * ? onto the stack via a notation like stack << value1 << value2.
 *  
 * ? Use the following test driver to test your code.
 * 
 * 
 * 
 * ? 1.3.2 Reverse Polish calculator
 * ? The Reverse Polish Notation (RPN) for arithmetic expression lists first the 
 * ? operands and then the operation. For example, the expression 2 × (2 + 3) is 
 * ? written 2 2 3 + ×. In order to evaluate the expression, one reads it from left 
 * ? to right and immediately replaces any operation and its operands with the 
 * ? corresponding result. For instance, the expression above evaluates as:
 * 
 * ? A stack is the ideal data structure to store the intermediate results as an 
 * ? RPN expression is evaluated, because each operation always involves the last 
 * ? n values computed (i.e., the ones at the top of the stack).
 *  
 * ? Write functions plus, minus, multiplies, divides and negate to implement a 
 * ? basic RPN calculator. Each function takes as input a stack containing the state
 * ? of the calculation and immediately replaces the top one or two elements with 
 * ? the operation result. Use the following test code to check that your code works.
 * 
 */


// ! we can use #include to include functions defined elsewhere. not just interfaces. 

#include "codes/stack_enhanced.hpp"
#include "codes/stack_enhanced_rpn.hpp"