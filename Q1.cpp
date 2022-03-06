/**
 * ? 1.1 Linear-time sorting 
 * 
 * ? 1.1.1 Radix sort
 * ? Consider non-negative integers of k binary digits each. We can represent each integer as a 
 * ? binary sequence ⟨ck−1ck−2 · · · c0⟩, where ci ∈ {0, 1} where ck−1 is the most significant 
 * ? digit.
 * 
 * ? Informally describe an algorithm that sort a sequence A of n such integers one digit per 
 * ? time, with an overall cost of O(kn).
 * 
 * 1. sort the integers according to their least significant bit
 * 2. then sort the integers using one bit up
 * 3. repeat until sorting the most signicant bit
 * 
 * the sort is then complete.
 * 
 * 
 * ? Optionally, write a C++ implementation radix_sort.hpp of this algorithm with an interface 
 * ? similar to merge_sort.hpp and test it using the following C++ driver program. Do this only 
 * ? if you have time as it is slightly tricky to get right.
 * 
 */

