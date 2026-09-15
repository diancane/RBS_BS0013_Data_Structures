int main() {
    int* p = new int{42};
    int* q = p;

    delete p;

    // Intentionally invalid for the AddressSanitizer exercise.
    delete q;

    // TODO: In a comment, explain why two pointer variables do not imply two allocations.
    //ans: p and q both hold the same address (q = p just copies the address), so there is still only one "int" on the heap, created by one "new".
    // Two pointer variables just mean two ways to reach that one object, not two objects. So the allocation must be released exactly once:
    // delete p; p = nullptr; q = nullptr;  
}
