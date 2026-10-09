#include <iostream>
#include <string>
class Animal
{
private:
    std::string name;
public:
    explicit Animal(const std::string& name):name(name) {}
    std::string getName() const
    {
        return name;
    }
    virtual void sound() const = 0;
    virtual ~Animal() = default;
};
class Dog:public Animal
{
public:
    using Animal::Animal;

    void sound() const override
    {
        std::cout << getName() << ": Гав!\n";
    }
};
class Puppy:public Dog
{
public:
    using Dog::Dog;
};
class Cat:public Animal
{
public:
    using Animal::Animal;
    void sound() const override
    {
        std::cout << getName() << ": Мяу!\n";
    }
};
class Flyable
{
public:
    virtual void fly() const = 0;
    virtual ~Flyable() = default;
};
class Swimmable
{
public:
    virtual void swim() const = 0;
    virtual ~Swimmable() = default;
};
class Duck:public Animal,public Flyable,public Swimmable
{
public:
    using Animal::Animal;
    void sound() const override
    {
        std::cout << getName() << ":Кря" << std::endl;
    }
    void fly() const override
    {
        std::cout << "Утка летит" << std::endl;
    }
    void swim() const override
    {
        std::cout << "Утка плывёт" << std::endl;
    }
};
void show(int value)
{
    std::cout << "Число:" << value << '\n';
}
void show(const std::string value)
{
    std::cout << "Текст:" << value << '\n';
}
int main()
{
    Dog dog("Бобик");
    Cat cat("Мурка");
    Duck duck("Дональд");
    Animal*animals[]={&dog,&cat,&duck};
    for (Animal*animal:animals)
        animal->sound();
    duck.fly();
    duck.swim();
    show(10);
    show("Привет");
}
