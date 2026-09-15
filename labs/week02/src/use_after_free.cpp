#include <iostream>

int main() {
    int* p = new int{42};
    delete p;

    // Intentionally invalid for the AddressSanitizer exercise.
    std::cout << *p << '\n';

    // TODO: In a comment, describe a correct lifetime/ownership repair.
    //ans: we should not delete p until after the last use, instead we move "delete p;"" to the end of the function (after the cout), or guard the read:
    //     int* p = new int{42};
    //     std::cout << *p << '\n';
    //     delete p;  
    //     p = nullptr;
}
