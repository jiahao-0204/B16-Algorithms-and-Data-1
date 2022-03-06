#ifndef __array_delete__
#define __array_delete__



template <typename T>
void array_delete(std::vector<T>& A, size_t index)
{
    assert(index <= A.size());

    int s = A.size();
    for (int i = index; i < s - 1; ++i) {
        A[i] = A[i + 1];
    }
    A.pop_back();
    
}




#endif // __array_delete__