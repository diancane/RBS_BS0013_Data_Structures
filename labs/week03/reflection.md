# Week 3 Reflection — Dynamic Arrays

Complete this file briefly but precisely.

## 1. Size, capacity, and storage

1. Can `size()` be smaller than `capacity()`? Explain.
ans: Yes, size() shows how many elements are currently stored, while capacity() shows how many elements can fit in the allocated storage. Therefore, a vector can have extra unused space.
2. Why must `size()` never exceed `capacity()`?
ans: Because capacity() is the amount of storage that has been allocated. If size() was bigger than capacity(), there would not be enough space to store all the elements.
3. Does every `push_back` allocate? What did `vector_growth` show?
ans: No. A new allocation is only needed when the current capacity is full.
4. What does `data()` identify?
ans: data() gives a pointer to the first element of the vector's storage. It identifies where the contiguous array of elements is stored.

## 2. Reallocation and pointer validity

Why can a pointer to an element become invalid after a capacity-changing `push_back`? Explain using **storage lifetime**, not only address changes.
ans: A pointer to an element can become invalid after a capacity-changing push_back because the vector may move its elements to a new storage area. 
The old storage is released, so the pointer points to storage whose lifetime has ended. Therefore, the old pointer must not be used to access the element.

## 3. Invariants

State the two representation invariants used by `IntVector`. Why is checking an invariant after every mutating operation useful?
ans: The two representation invariants are "0 <= size_ <= capacity_" and "capacity_ == 0 if and only if data_ == nullptr"
Checking the invariant after mutating operations is useful because it helps us find mistakes early. It makes sure that the IntVector is always in a valid state after changes.

## 4. Complexity

Fill in the table.

| Operation | Complexity | Why? |
|---|---|---|
| `at(i)` | Theta(1) | The element can be accessed directly using its index. |
| `push_back` without growth | Theta(1) | We only store the new value and increase size_. |
| `push_back` that reallocates | Theta(n) | The existing elements have to be copied to the new storage. |
| `push_back` amortized over many appends | Theta(1) | Most appends are cheap, and expensive reallocations happen less often. |
| copy construction | Theta(n) | The logical elements have to be copied to new storage. |

Why does doubling capacity give amortized constant-time append even though some individual appends are linear?
ans: When the capacity doubles, we copy the existing elements, which takes Theta(n) time. However, this does not happen for every append. After a resize, many new elements can be added without another resize. The total number of copied elements over many appends is proportional to n, so the average cost of one append is Theta(1).

## 5. Deep copy

What would go wrong if copying `IntVector` only copied `data_`, `size_`, and `capacity_` member-by-member? Name at least two correctness/ownership problems.
ans: If copying IntVector only copied data_, size_, and capacity_, both objects would point to the same array. This could cause two problems: Changing one vector could also change the other vector, and both objects would try to delete the same array, which could cause a double deletion and a program error.
A deep copy creates a separate array and copies the elements into it.

## 6. STL comparison

Give one reason to use `std::vector<int>` in production code instead of this teaching implementation, and one reason implementing `IntVector` is still useful in a data-structures course.
ans: One reason to use std::vector<int> in production is that it is already tested, reliable, and provides many useful features.
Implementing IntVector is still useful in a data-structures course because it helps us understand how a dynamic array works internally, including memory allocation, resizing, copying, and pointer validity.