#include <iostream>                                      // Includes the iostream library for input and output

class Animal                                             // Defines the base class Animal
{
public:                                                   // Starts the public section of Animal

    virtual void sound() const                            // Declares sound() as a virtual function
    {
        std::cout << "Animal makes a sound\n";            // Displays the general animal sound
    }

    virtual ~Animal() = default;                          // Defines a virtual destructor for safe polymorphic use
};

class Dog : public Animal                                 // Defines Dog class inheriting from Animal
{
public:                                                   // Starts the public section of Dog

    void sound() const override                            // Overrides the virtual sound() function
    {
        std::cout << "Dog barks\n";                       // Displays the sound made by a dog
    }
};

class Cat : public Animal                                 // Defines Cat class inheriting from Animal
{
public:                                                   // Starts the public section of Cat

    void sound() const override                            // Overrides the virtual sound() function
    {
        std::cout << "Cat meows\n";                       // Displays the sound made by a cat
    }
};

int main()                                              // Main function where program execution starts
{
    Dog dog;                                             // Creates an object of the Dog class

    Cat cat;                                             // Creates an object of the Cat class

    Animal* animal = &dog;                               // Creates Animal pointer pointing to Dog object

    animal->sound();                                     // Calls Dog's sound() due to run-time polymorphism

    animal = &cat;                                       // Changes the pointer to point to Cat object

    animal->sound();                                     // Calls Cat's sound() due to run-time polymorphism

    return 0;                                            // Returns 0 to indicate successful execution
}