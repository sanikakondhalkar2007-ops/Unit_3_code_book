#include <iostream>                                      // Includes the iostream library for input and output

class Base                                                // Defines the base class
{
public:                                                   // Starts the public section of Base

    void display() const                                  // Defines a non-virtual display function
    {
        std::cout << "Base display function\n";           // Displays the Base class message
    }
};

class Derived : public Base                               // Defines Derived class inheriting from Base
{
public:                                                   // Starts the public section of Derived

    void display() const                                  // Defines another display function in Derived
    {
        std::cout << "Derived display function\n";        // Displays the Derived class message
    }
};

int main()                                              // Main function where program execution starts
{
    Derived derivedObject;                              // Creates an object of the Derived class

    Base* basePointer = &derivedObject;                 // Creates a Base pointer pointing to Derived object

    basePointer->display();                              // Calls Base display because function is not virtual

    return 0;                                           // Returns 0 to indicate successful execution
}