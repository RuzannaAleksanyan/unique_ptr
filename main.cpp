#include "unique_ptr.hpp"
#include <iostream>

struct A {
    int value;

    A(int val) : value(val) {
        std::cout << "Constructing A: " << value << std::endl;
    }

    ~A() {
        std::cout << "Destructing A: " << value << std::endl;
    }
};

void test_unique_ptr() {
    std::cout << "\nTest 1: Basic Functionality" << std::endl;
    unique_ptr<A> ptr1(new A(1));
    ptr1->value = 10;
    std::cout << "Value: " << ptr1->value << std::endl;

    std::cout << "\nTest 2: Move Assignment" << std::endl;
    unique_ptr<A> ptr2(new A(2));
    ptr2->value = 20;
    ptr1 = std::move(ptr2);
    if (ptr1.get() != nullptr) {
        std::cout << "Value (ptr1): " << ptr1->value << std::endl;
    }
    if (ptr2.get() == nullptr) {
        std::cout << "ptr2 is empty" << std::endl;
    }

    std::cout << "\nTest 3: Reset" << std::endl;
    ptr1.reset(new A(3));
    std::cout << "Value after reset: " << ptr1->value << std::endl;
    
    std::cout << "\nTest 4: Release" << std::endl;
    A* raw_ptr = ptr1.release();
    if (ptr1.get() == nullptr) {
        std::cout << "ptr1 is now empty after release." << std::endl;
    }
    delete raw_ptr; // Manually delete released pointer to avoid memory leak
    
    std::cout << "\nTest 5: Swap" << std::endl;
    unique_ptr<A> ptr3(new A(4));
    unique_ptr<A> ptr4(new A(5));
    std::cout << "Before swap: ptr3 = " << ptr3->value << ", ptr4 = " << ptr4->value << std::endl;
    ptr3.swap(ptr4);
    std::cout << "After swap: ptr3 = " << ptr3->value << ", ptr4 = " << ptr4->value << std::endl;
}

int main() {
    test_unique_ptr();
    return 0;
}