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

int main() {
    unique_ptr<A> ptr1(new A(1));

    ptr1->value = 10;
    std::cout << "Value: " << ptr1->value << std::endl;

    unique_ptr<A> ptr2(new A(2));
    ptr2->value = 20;
    std::cout << "Value: " << ptr2->value << std::endl;

    ptr1 = std::move(ptr2); 

    if (ptr1.get() != nullptr) {
        std::cout << "Value (ptr1): " << ptr1->value << std::endl;
    }

    if (ptr2.get() == nullptr) {
        std::cout << "ptr2 is empty" << std::endl;
    }

    return 0;
}
