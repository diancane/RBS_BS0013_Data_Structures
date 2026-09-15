# Week 2 Reflection

Answer briefly but precisely.

## 1. Pointer copying

Why does copying a pointer value not copy the pointed-to object?

ans: A pointer just holds an address, so copying the pointer copies the address,
not the thing it points to and both pointers now point at the same one object. 
To copy the object itself we have to use `*p` to grab the value.

## 2. Reachability versus lifetime

Explain how an object can still be alive but no longer reachable by traversing from a particular head pointer.

ans: Alive means the object still exists in memory. 
"Reachable" means that we can get to it by following pointers from the head, so if we move the head past a node, 
that old node is still sitting in memory, but nothing in the chain points to it anymore. 
We can't get to it, so we can't use it or free it.

## 3. Dangling pointers

When a pointer becomes dangling, what changed: the pointer's stored numeric value, the target object's lifetime, or necessarily both?

ans: Only the object's lifetime changed, meaning it died. 
The pointer still holds the same address and that number didn't change. So it's not both. 
The pointer just points at something that no longer exists.

## 4. Ownership responsibility

Why can two pointers to one dynamically allocated object not both independently `delete` it?

ans: The first "delete" frees the memory, and the second "delete" tries to free the same memory again, 
making a "double free" and it's undefined behavior (may crash or corrupt things). 
Only one owner should delete, and only once.

## 5. `nullptr`

Why does assigning `nullptr` to a raw pointer not release dynamically allocated storage?

ans: Setting a pointer to "nullptr" just changes what the pointer holds, it writes "nothing" over the address. 
The heap object is still there, untouched, and now nobody points to it. That's a leak. 
Only "delete" actually gives the memory back.

## 6. Linked traversal complexity

Why is traversal of `n` linked nodes Θ(n) even though following one `next` pointer is Θ(1)?

ans: One "next" step is O(1), it's a single quick operation.
But to walk the whole chain of "n" nodes, we do that O(1) step "n" times. So the total is O(n). 

## 7. Invariants

State two invariants that should hold for the final chain `10 -> 20 -> 25 -> 30 -> null`.

ans: Every node points to the next one, and the last node points to "nullptr" (the chain ends cleanly).
The values go up in order: 10 < 20 < 25 < 30, and we can reach every node by starting at the head and following "next".
