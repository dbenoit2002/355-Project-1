//Do not use pointer arithmetic on polymorphic objects

#include <iostream>

class Animal {
public:
    virtual void speak() const = 0;
    virtual ~Animal() = default; 
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }
};

void makeAnimalSpeak(const Animal& animal) {
    animal.speak();
}

int main() {
    Dog dog;
    Cat cat;

    makeAnimalSpeak(dog);
    makeAnimalSpeak(cat);

    return 0;
}
