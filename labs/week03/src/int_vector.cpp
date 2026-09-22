#include "int_vector.hpp"

#include <stdexcept>
#include <cassert>

IntVector::~IntVector() {
    // TODO: release the owned array exactly once.
    delete[] data_;

    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;

}

IntVector::IntVector(const IntVector& other) {
    // TODO: allocate independent storage and copy the logical elements.
    size_ = other.size_;
    capacity_ = other.capacity_;
    
    if (capacity_ == 0) {
        data_ = nullptr;
    } else {
        data_ = new int[capacity_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
}

void IntVector::check_invariant() const {
    // TODO: assert the Week 3 representation invariants.
    assert(size_ >= 0);
    assert(size_ <= capacity_);

    if (capacity_ == 0) {
        assert(data_ == nullptr);
    } else {
        assert(data_ != nullptr);
    }
}

void IntVector::grow() {
    // TODO: geometric growth policy: 0 -> 1, otherwise double capacity.
    // Preserve size_ and all existing logical elements.
    int new_capacity;
    if (capacity_ == 0) {
        new_capacity = 1;
    } else {
        new_capacity = capacity_ * 2;
    }

    int* new_data = new int[new_capacity];

    for (int i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }

    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;   
}

void IntVector::push_back(int value) {
    // TODO: grow only when size_ == capacity_, append, update size_,
    // and finish in a valid representation state.
    if (size_ == capacity_) {
        grow();
    }
    data_[size_] = value;
    size_++;
    check_invariant(); 
}

