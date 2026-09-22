#include <iostream>                         // Includes the iostream library for input and output

int add(int first, int second)             // Defines add() function with two integer parameters
{
    return first + second;                  // Returns the sum of the two integers
}

double add(double first, double second)     // Defines another add() function with two double parameters
{
    return first + second;                  // Returns the sum of the two double values
}

int add(int first, int second, int third)  // Defines another add() function with three integer parameters
{
    return first + second + third;          // Returns the sum of the three integers
}

int main()                                   // Main function where program execution starts
{
    std::cout << "Sum of two integers: "    // Displays the message
              << add(10, 20) << '\n';       // Calls add() with two integers and displays the result

    std::cout << "Sum of two doubles: "     // Displays the message
              << add(2.5, 3.7) << '\n';     // Calls add() with two double values and displays the result

    std::cout << "Sum of three integers: "  // Displays the message
              << add(10, 20, 30) << '\n';   // Calls add() with three integers and displays the result

    return 0;                                // Returns 0 to indicate successful execution
}