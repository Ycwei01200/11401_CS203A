# Array vs. Linked List 🔄

## Time Complexity & Characteristics Comparison

| Operation                 | Array                               | Linked List                                  |
| ------------------------- | ----------------------------------- | -------------------------------------------- |
| **Access**                | O(1) - Direct access                | O(n) - Sequential traversal                  |
| **Search**                | O(n) - Linear search                | O(n) - Sequential traversal                  |
| **Insert**                | O(n) - Find target + shift elements | O(1) - With pointer / O(n) - Without pointer |
| **Delete**                | O(n) - Find target + shift elements | O(1) - With pointer / O(n) - Without pointer |
| **Swap**                  | O(1) - Direct element swap          | O(n) - Pointer manipulation                  |
| **Sort** (Selection Sort) | O(n²)                               | O(n²)                                        |
| **Memory Overhead**       | Low                                 | Moderate (extra pointers)                    |
| **Flexibility**           | Static (fixed size)                 | Dynamic (grows/shrinks)                      |
| **Storage**               | Contiguous memory                   | Non-contiguous memory                        |
| **Extra Variables**       | 1 variable (for swapping values)    | 2-4 pointers (for node manipulation)         |

---

## When to Use Each

### Use **Array** when:
- ✅ Index is known
- ✅ Fast random access is needed
- ✅ Memory is contiguous
- ✅ Size is relatively fixed

### Use **Linked List** when:
- ✅ Frequent insertions/deletions
- ✅ Dynamic size requirements
- ✅ No need for random access
- ✅ Memory fragmentation is acceptable



