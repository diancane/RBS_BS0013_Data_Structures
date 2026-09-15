#include <iostream>

int main() {
    int value = 42;
    int* p = nullptr;

    std::cout << "initially null: " << std::boolalpha << (p == nullptr) << '\n';

    p = &value;
    if (p != nullptr) {
        std::cout << "live value: " << *p << '\n';
    }

    int* dangling = nullptr;
    {
        int temporary = 99;
        dangling = &temporary;
        std::cout << "inside scope: " << *dangling << '\n';
    }

    // TODO: Explain why dangling must not be dereferenced here.
    //ans: Temporary` was destroyed when its scope ended at line 19, so "dangling" still holds the old address but the object there no longer exists

    // Do not add: std::cout << *dangling;

    dangling = nullptr;
    std::cout << "dangling reset to null: " << (dangling == nullptr) << '\n';
}
