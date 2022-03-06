/**
 * 
 * ? 1.8 Hashing
 * 
 * ? 1.8.1 Worst case complexity for multiple chaining
 * ? Suppose that keys k are drawn from a finite set K (sometimes called the 
 * ? universe). Suppose that we have n keys k1,...,kn ∈ K to hash using m chains, 
 * ? such that|K| > m·n. Show that we can choose then n keys so that they all hash 
 * ? to the same chain, so that the worst case complexity of retrieving keys from 
 * ? the table is Ω(n).
 * 
 * ! ????
 * 
 * ? 1.8.2 Other usages of hash functions
 * ? Suppose you have a file such as a photo or video. Explain how a hash 
 * ? function can be used to create a compact “signature” of the file to verify 
 * ? its integrity. Specifically, explain how knowledge of the signature can be 
 * ? used to tell with high probability whether the file has been modified 
 * ? without requiring knowledge of the original file. Also explain how you 
 * ? would choose the size m of the hash space for this application.
 * 
 * 
 * we can segment the file into different chunks. 
 * view each chuck as a number
 * mod a prime number to obtain a hash
 * combine these hash to form a signature
 * 
 * 
 * when downloading the file, a hash value is given as well. after downloading,
 * we can compute the hash and compare it with the provided one to see if the 
 * file downloaded is the same
 * 
 * 
 * choose m to be a large prime number that can be represented using hexadecimal
 * for compact representation of hash. 
 * 
 * 
 * 
 * ? 1.8.3 Division method for large keys
 * ? The division method consists in computing the remainder k mod m of the 
 * ? division of key k, regarded as a large natural number, by m.
 * 
 * ? Suppose that the key is originally a string ⟨cq−1 cq−2 · · · c0⟩ where 
 * ? ci ∈ [0, 255] is a character or byte. Except for very short string, the 
 * ? corresponding number 
 *  
 * ? does not fit in any of the standard atomic data types such as char, short, 
 * ? int etc. The size of these data types is bounded by the size of the 
 * ? underlying CPU registers, and are thus usually up to 64 bit long. While 
 * ? the C++ operator % can be used to compute the remainder for atomic data 
 * ? type, it is unclear how this can be done for numbers that exceed 64 bits.
 *  
 * ? Write a function uint32_t hash(const std::string& str, const uint32_t m) 
 * ? that takes as input an arbitrary long string str and a divisor m and 
 * ? computes
 *  
 * ? where c denotes the string str and q is the number of characters in the 
 * ? string. Make use of the properties of modular arithmetic:
 * ? - a+b mod m = (a mod m)+(b mod m) 
 * ? - ab mod m = (a mod m)x(b mod m)
 * 
 * see below
 * 
 * 
 * ? 1.8.4 Permutation invariance of the division method
 * ? Show that choosing m = 255 in the previous question results in hashes that 
 * ? are invariant to permutation of the characters in the string (meaning for 
 * ? example that h(ciao) = h(oaic)).
 * 
 * 
 * see below
 * 
 */


#include <string>
#include <math.h>

#include <iostream>

uint32_t hash(const std::string & str, const uint32_t m) {
    uint32_t sum = 0;


    for (int i = 0; i < str.size(); i++){
        
        char s = str.at(i);
        int si = (int)s;

        sum += (si % m) * pow(256 % m, i);
    }

    return sum;
};


int main() {
    std::cout << hash("ciao", 255) << std::endl;
    std::cout << hash("oaci", 255) << std::endl;
}