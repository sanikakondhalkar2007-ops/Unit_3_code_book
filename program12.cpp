#include <iostream>                                      // Includes the iostream library for input and output
#include <memory>                                        // Includes memory library for smart pointers
#include <vector>                                        // Includes vector library for storing multiple objects

class Shape                                               // Defines the abstract base class Shape
{
public:                                                   // Starts the public section of Shape

    virtual double area() const = 0;                      // Declares pure virtual area() function

    virtual void displayName() const = 0;                // Declares pure virtual displayName() function

    virtual ~Shape() = default;                           // Defines a virtual destructor
};

class Rectangle : public Shape                             // Defines Rectangle class inheriting from Shape
{
private:                                                  // Starts the private section of Rectangle

    double length;                                        // Stores the rectangle length

    double width;                                         // Stores the rectangle width

public:                                                   // Starts the public section of Rectangle

    Rectangle(double givenLength, double givenWidth)      // Defines Rectangle constructor
        : length(givenLength), width(givenWidth)          // Initializes length and width
    {
    }

    double area() const override                           // Implements the area() function
    {
        return length * width;                            // Calculates and returns rectangle area
    }

    void displayName() const override                      // Implements the displayName() function
    {
        std::cout << "Rectangle";                         // Displays the name Rectangle
    }
};

class Circle : public Shape                                // Defines Circle class inheriting from Shape
{
private:                                                  // Starts the private section of Circle

    double radius;                                        // Stores the circle radius

public:                                                   // Starts the public section of Circle

    explicit Circle(double givenRadius)                   // Defines Circle constructor
        : radius(givenRadius)                             // Initializes radius
    {
    }

    double area() const override                           // Implements the area() function
    {
        constexpr double PI = 3.141592653589793;          // Defines the constant value of PI

        return PI * radius * radius;                      // Calculates and returns circle area
    }

    void displayName() const override                      // Implements the displayName() function
    {
        std::cout << "Circle";                            // Displays the name Circle
    }
};

int main()                                              // Main function where program execution starts
{
    std::vector<std::unique_ptr<Shape>> shapes;           // Creates a vector to store Shape smart pointers

    shapes.push_back(std::make_unique<Rectangle>(5.0, 3.0)); // Creates Rectangle and stores its pointer

    shapes.push_back(std::make_unique<Circle>(2.0));      // Creates Circle and stores its pointer

    for (const auto& shape : shapes)                      // Loops through every shape in the vector
    {
        shape->displayName();                             // Calls the correct derived displayName() function

        std::cout << " Area: " << shape->area() << '\n';  // Calls the correct derived area() function
    }

    return 0;                                            // Returns 0 to indicate successful execution
}