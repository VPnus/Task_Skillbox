#include <iostream>

class Toy {
public:
    Toy(const std::string& name) : name(name) {
        std::cout << "Creating toy " << name << std::endl;
    }

    ~Toy() {
        std::cout << "Destroying toy " << name << std::endl;
    }

    std::string getName() const {
        return name;
    }

private:
    std::string name;
};


class shared_ptr_toy {
public:
    shared_ptr_toy(Toy* toy = nullptr) : ptr(toy), ref_count(nullptr) {
        if (ptr) {
            ref_count = new int(1);
        }
    }

    shared_ptr_toy(const shared_ptr_toy& other) : ptr(other.ptr), ref_count(other.ref_count) {
        if (ref_count) {
            (*ref_count)++;
        }
    }

    ~shared_ptr_toy() {
        if (ref_count) {
            (*ref_count)--;
            if (*ref_count == 0) {
                delete ptr;
                delete ref_count;
            }
        }
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other) {
        if (this != &other) {
            if (ref_count && (*ref_count) > 0) {
                (*ref_count)--;
                if (*ref_count == 0) {
                    delete ptr;
                    delete ref_count;
                }
            }
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ref_count) {
                (*ref_count)++;
            }
        }
        return *this;
    }

    Toy* operator->() const {
        return ptr;
    }

    Toy& operator*() const {
        return *ptr;
    }

private:
    Toy* ptr;
    int* ref_count;
};


shared_ptr_toy make_shared_toy(const std::string& name) {
    return shared_ptr_toy(new Toy(name));
}

int main() {
    shared_ptr_toy ptr1 = make_shared_toy("Ball");
    shared_ptr_toy ptr2 = ptr1;
    std::cout << ptr1->getName() << std::endl;
    std::cout << ptr2->getName() << std::endl;
    ptr2 = make_shared_toy("Doll");
    std::cout << ptr1->getName() << std::endl;
    std::cout << ptr2->getName() << std::endl;
    return 0;
}