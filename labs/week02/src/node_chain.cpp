#include <iostream>

struct Node {
    int value;
    Node* next = nullptr;
};

void print_chain(const Node* head) {
    for (const Node* current = head; current != nullptr; current = current->next) {
        std::cout << current->value << ' ';
    }
}

int main() {
    Node a{10};
    Node b{20};
    Node c{30};
    Node d{25};

    a.next = &b;
    b.next = &c;

    // Task 6A: temporarily rewire so traversal from a is 10 -> 30 -> null.
    // Explain in a comment why b still exists even when unreachable from a.
    a.next = &c;
    // ans: b still exists because a, b, c, and d are local variables on the stack.
    // Their lifetime lasts until main() ends, regardless of who points to them.
    // Rewiring a.next only changes the links, not the nodes. So b is alive but
    // unreachable from a — alive and reachable are two separate things.

    // Task 6B: restore and then insert d so the final chain is:
    // 10 -> 20 -> 25 -> 30 -> null
    a.next = &b;    // 10 -> 20
    b.next = &d;    // 20 -> 25
    d.next = &c;    // 25 -> 30
    c.next = nullptr;  // 30 -> null

    // Invariants after insertion:
    // 1. Starting at a and following next visits 10, 20, 25, 30, each exactly once, then stops.
    // 2. The last node (c) has next == nullptr.
    // 3. Every next pointer points to a live local Node in this function,
    //    so no link refers to an object whose lifetime has ended.
    // 4. Only the `next` links were changed — no `value` fields were touched.

    print_chain(&a);
    std::cout << '\n';
}