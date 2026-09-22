#include <iostream>                                      // Includes the iostream library for input and output

class Shape                                               // Defines the abstract base class Shape
{
public:                                                   // Starts the public section of Shape

    virtual double area() const = 0;                      // Declares a pure virtual function making Shape abstract

    virtual ~Shape() = default;                           // Defines a virtual destructor
};

class Rectangle : public Shape                             // Defines Rectangle class inheriting from Shape
{
private:                                                  // Starts the private section of Rectangle

    double length;                                        // Stores the length of the rectangle

    double width;                                         // Stores the width of the rectangle

public:                                                   // Starts the public section of Rectangle

    Rectangle(double givenLength, double givenWidth)      // Defines the Rectangle constructor
        : length(givenLength), width(givenWidth)          // Initializes length and width
    {
    }

    double area() const override                           // Implements the pure virtual area() function
    {
        return length * width;                            // Calculates and returns rectangle area
    }
};

int main()                                              // Main function where program execution starts
{
    Rectangle rectangle(8.0, 4.0);                       // Creates Rectangle object with length 8 and width 4

    std::cout << "Rectangle Area: "                     // Displays the rectangle area message
              << rectangle.area() << '\n';              // Calls area() and displays the calculated area

    return 0;                                            // Returns 0 to indicate successful execution
}