#include <iostream>
#include <vector>

 class Talent{
 public:
    virtual void show() = 0;
    virtual ~Talent() {}
};

class Dog
{
private:
    std::string name_dog;
    std::vector<Talent*> dog_talent;

public:
    Dog(std::string _name_dog) : name_dog(_name_dog){};
    ~Dog()
    {
        for(int i=0; i < dog_talent.size(); ++i)
        {
            delete dog_talent[i];
        }
    }

    void add_talent(Talent* talent)
    {
        dog_talent.emplace_back(talent);
    }

    void show_talents()
    {
        std::cout << "This is " << name_dog << " and it has some talents: " << std::endl;
        for (Talent* talent : dog_talent) {
            talent->show();
        }
    }


};

class Swimming : public Talent
{
     void show()
    {
        std::cout << "\tIt can Swim" << std::endl;
    }
};

class Dancing : public Talent
{
     void show()
    {
        std::cout << "\tIt can Dance" << std::endl;
    }
};

class Counting : public Talent
{
     void show()
    {
        std::cout << "\tIt can Count" << std::endl;
    }
};



int main() {
    Dog dog("Steve");
    dog.add_talent(new Dancing());
    dog.add_talent(new Swimming());

    dog.show_talents();
    return 0;
}
