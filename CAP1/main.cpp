#include <iostream>
#include <string>

struct Person
{
public:
    Person() : age(25), name("JAN"), iq(144.6) {} 

    int age;
    std::string name;
    double iq;
};

int main()
{
    // argument pack
    auto [age, name, iq] = Person();
    std::cout << "Age = " << age << " Name = " << name << " iq = " << iq << "\n";

    // If statement with initializer
    if(auto condition(2 == 2); condition)
    {
        std::cout << condition << "\n";
    }
    else
    {
        std::cout << condition << "\n";
    }
}