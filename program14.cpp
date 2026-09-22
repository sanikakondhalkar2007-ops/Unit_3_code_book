#include <iostream>                                      // Includes the iostream library for input and output

class Base                                                // Defines the Base class
{
public:                                                   // Starts the public section of Base

    virtual void display() const                          // Defines a virtual display function
    {
        std::cout << "Base object\n";                     // Displays the Base object message
    }

    virtual ~Base() = default;                            // Defines a virtual destructor
};

class Derived : public Base                               // Defines Derived class inheriting from Base
{
public:                                                   // Starts the public section of Derived

    void display() const override                          // Overrides the display function of Base
    {
        std::cout << "Derived object\n";                  // Displays the Derived object message
    }
};

void displayByValue(Base object)                           // Defines a function that receives Base object by value
{
    object.display();                                      // Calls display() using the copied Base object
}

void displayByReference(const Base& object)               // Defines a function that receives Base object by reference
{
    object.display();                                      // Calls the correct derived display() function
}

int main()                                                 // Main function where program execution starts
{
    Derived derived;                                       // Creates an object of the Derived class

    std::cout << "Passing by value: ";                     // Displays the message for passing by value

    displayByValue(derived);                               // Passes Derived object by value causing object slicing

    std::cout << "Passing by reference: ";                // Displays the message for passing by reference

    displayByReference(derived);                           // Passes Derived object by reference without slicing

    return 0;                                              // Returns 0 to indicate successful execution
}