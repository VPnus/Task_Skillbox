#include <iostream>
#include <memory>

class Toy {
public:
   Toy(const std::string& name) {
       name_ = name;
   }
   std::string getName() {
       return name_;
   }
   ~Toy() {
       std::cout << "Toy " << name_ << " was dropped " << std::endl;
   }
private:
   std::string name_;
};

class Dog {
public:
    void getToy(std::shared_ptr<Toy> toy) {
        if (currentToy_ == toy) {
            std::cout << "I already have this toy." << std::endl;
        } else if (toy.use_count() > 1) {
            std::cout << "Another dog is playing with this toy." << std::endl;
        } else {
            currentToy_ = toy;
            std::cout << "Dog picked up toy " << toy->getName() << std::endl;
        }
    }

    void dropToy() {
        if (currentToy_ == nullptr) {
            std::cout << "Nothing to drop." << std::endl;
        } else {
            std::cout << "Dog dropped toy " << currentToy_->getName() << std::endl;
            currentToy_.reset();
        }
    }

private:
    std::shared_ptr<Toy> currentToy_;
};

int main() {
    Dog dog1;
    Dog dog2;

    std::shared_ptr<Toy> toy1 = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> toy2 = std::make_shared<Toy>("Bone");

    dog1.getToy(toy1);
    dog2.getToy(toy1);
    dog1.getToy(toy2);
    dog2.getToy(toy2);

    dog1.dropToy();
    dog2.dropToy();
    dog1.dropToy();

    return 0;
}