/** 
 * ? 1.2 Arrays
 * 
 * ? 1.2.1 Complexity of ArrayInsert
 * ? What is the Big-O complexity of ArrayInsert?
 * 
 * O(n), where n is the size of the array.
 * 
 * this is because 'std::vector' class uses array as the underlying storage. 
 * hence all terms behind the inserted index are moved one position backwards.
 * 
 * 'std::list' or 'std::forward_list' stores the pointer of the next element, 
 * thus the complexity of insert is constant at O(1).
 * 
 * 
 * ? 1.2.2 Deleting elements from an array
 * ? Design an algorithm ArrayDelete to delete the element at position i in an 
 * ? array A. Then, implement the algorithm as a C++ template function 
 * ? void array_delete(std::vector<T>&, size_t) and test it using the following 
 * ? driver.
 * 
 * ArrayDelete(A, i):
 *      Input: An array A = (A0, ..., An−1), and an index i
 *      Output: The array (A0, ..., Ai−1, Ai+1, ..., An−1).
 * 
 * 1. For j = i, ..., n-2: 
 *  1. Set Aj <- Aj+1
 * 2. Set An-1 <- null 
 * 
 * 
 * 
 * ArrayInsert(A, i, x):
 *      Input: An array A = (A0, ..., An−1), a new value x and an index i
 *      Output: The array (A0, ..., Ai−1, x, Ai, ..., An−1).
 * 
 * 1. For j = n, ..., i+1: 
 *  1. Set Aj <- Aj−1
 * 2. Set Ai <- x 
 * 
 * 
 */

#include <iostream>
#include <vector>


template <typename T>
void array_delete(std::vector<T>& A, size_t index)
{
    assert(index < A.size());

    int s = A.size();
    for (int i = index; i < s - 1; ++i) {
        A[i] = A[i + 1];
    }
    A.pop_back();
}


template <typename T>
void print_vector(std::vector<T> v){
    
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    };

    std::cout << std::endl;
}


int main(){
    std::vector<float> A;
    
    A.push_back(0);
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    
    std::cout << "Initial array" << std::endl;
    print_vector(A);
    
    std::cout << "Remove index 1" << std::endl;
    array_delete(A, 1);
    print_vector(A);
    
    std::cout << "Remove index 3" << std::endl;
    array_delete(A, 3);
    print_vector(A);
    
    return 0;

}