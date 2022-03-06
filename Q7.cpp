/**
 * 
 * ! heap by default is a max heap, where largest element is at top
 * 
 * ? 1.7 Heaps
 * 
 * 
 * ? 1.7.1 Building a heap
 * ? In the notes, we have discussed the BuildHeap algorithm, for building 
 * ? a heap given an initial vector A of values:
 * 
 * ? This algorithm builds the heap starting from the leaves of the binary 
 * ? tree and working its way towards the root. Alternatively, we can build 
 * ? a heap starting from the root and moving towards the leaves. The idea 
 * ? is to progressively include elements A0, A1 etc in the heap, which 
 * ? amounts to adding one more leaf to the corresponding binary tree. Each 
 * ? time this is done, one calls SiftUp on the last element added to 
 * ? restore the heap property. In pseudocode:
 *  
 * ? Discuss the relation between BuildHeapAlt and PriorityEnqueue and 
 * ? compare the complexity of BuildHeap and BuildHeapAlt.
 * 
 * BuildHeapAlt is the same as PriorityEnqueue, progressively enqueue the 
 * next element from the array to the queue.
 * 
 * building heap from bottom up
 * - 1/2 * n sift down (since the rest are single element heap already)
 * - each sift down involve at most n element, thus log(n) sifting operations
 * - O(n log n)
 * 
 * building heap from top down 
 * - n sift up
 * - each sift up involve at most n element, thus log(n) sifting operations
 * - O(n log n)
 * 
 * building from bottom up involves less sifting,  thus should have lower cost.
 * 
 * # n log n is pessimistic
 * since number of layers log(i) during sifting is always lower than log(n), 
 * the real cost will be lower.
 * 
 * 
 * 
 * 
 * ? 1.7.2 Building a heap vs sorting
 * ? Discuss whether sorting an array A can be an alternative implementation 
 * ? of BuildHeap.
 * 
 * for a sorted array, element to the right will always be smaller than elements
 * to the left, 
 * 
 * conversion to binary tree representation will then have lower elements smaller 
 * than higher elements
 * 
 * which is a heap.
 * 
 * 
 * 
 * ? 1.7.3 Updating the priority of a queued element
 * ? Discuss how you could use SiftUp and SiftDown to update the priority of an 
 * ? element in a heap, used as a priority queue.
 * 
 * assuming a max heap
 * if the priority becomes larger, call SiftUp on the element
 * if the priority becomes smaller, call SiftDown on the element
 * 
 */