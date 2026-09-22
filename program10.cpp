#include <iostream>                                      // Includes the iostream library for input and output

class Shape                                               // Defines the base class Shape
{
public:                                                   // Starts the public section of Shape

    virtual double area() const                           // Declares area() as a virtual function
    {
        return 0.0;                                       // Returns 0.0 as the default area
    }

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

    double area() const override                           // Overrides the virtual area() function
    {
        return length * width;                            // Returns length × width
    }
};

class Circle : public Shape                                // Defines Circle class inheriting from Shape
{
private:                                                  // Starts the private section of Circle

    double radius;                                        // Stores the radius of the circle

public:                                                   // Starts the public section of Circle

    explicit Circle(double givenRadius)                   // Defines the Circle constructor
        : radius(givenRadius)                             // Initializes radius
    {
    }

    double area() const override                           // Overrides the virtual area() function
    {
        constexpr double PI = 3.141592653589793;          // Defines the constant value of PI

        return PI * radius * radius;                      // Returns the area of the circle
    }
};

void printArea(const Shape& shape)                         // Defines function accepting a Shape reference
{
    std::cout << "Area: " << shape.area() << '\n';         // Calls the correct derived area() function
}

int main()                                              // Main function where program execution starts
{
    Rectangle rectangle(5.0, 3.0);                       // Creates Rectangle with length 5 and width 3

    Circle circle(2.0);                                  // Creates Circle with radius 2

    printArea(rectangle);                                // Passes Rectangle to printArea()

    printArea(circle);                                   // Passes Circle to printArea()

    return 0;                                            // Returns 0 to indicate successful execution
}