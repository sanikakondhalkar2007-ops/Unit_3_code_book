#include <iostream>                                      // Includes the iostream library for input and output

class Base                                                // Defines the Base class
{
public:                                                   // Starts the public section of Base

    virtual ~Base()                                       // Defines a virtual destructor in the Base class
    {
        std::cout << "Base destructor\n";                 // Displays the Base destructor message
    }
};

class Derived : public Base                               // Defines Derived class inheriting from Base
{
public:                                                   // Starts the public section of Derived

    ~Derived() override                                   // Defines the Derived destructor and overrides Base destructor
    {
        std::cout << "Derived destructor\n";              // Displays the Derived destructor message
    }
};

int main()                                                // Main function where program execution starts
{
    Base* pointer = new Derived();                        // Creates a Derived object and stores its address in a Base pointer

    delete pointer;                                       // Deletes the object through the Base pointer

    return 0;                                              // Returns 0 to indicate successful execution
}