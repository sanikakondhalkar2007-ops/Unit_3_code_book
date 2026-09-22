#include <iostream>                         // Includes the iostream library for input and output

int calculateArea(int side)                 // Defines calculateArea() for calculating square area
{
    return side * side;                     // Returns side × side as the square area
}

int calculateArea(int length, int width)    // Defines calculateArea() for calculating rectangle area
{
    return length * width;                  // Returns length × width as the rectangle area
}

double calculateArea(double radius)          // Defines calculateArea() for calculating circle area
{
    constexpr double PI = 3.141592653589793; // Declares a constant value of PI

    return PI * radius * radius;             // Returns PI × radius × radius as circle area
}

int main()                                  // Main function where program execution starts
{
    std::cout << "Square Area: "            // Displays the square area message
              << calculateArea(5) << '\n';  // Calls calculateArea() with side = 5

    std::cout << "Rectangle Area: "         // Displays the rectangle area message
              << calculateArea(6, 4) << '\n'; // Calls calculateArea() with length = 6 and width = 4

    std::cout << "Circle Area: "            // Displays the circle area message
              << calculateArea(2.0) << '\n'; // Calls calculateArea() with radius = 2.0

    return 0;                               // Returns 0 to indicate successful execution
}