#include <iostream>                                      // Includes the iostream library for input and output

class Complex                                             // Defines a class named Complex
{
private:                                                  // Starts the private section of the class

    int real;                                             // Declares a variable to store the real part

    int imaginary;                                        // Declares a variable to store the imaginary part

public:                                                   // Starts the public section of the class

    Complex(int realPart = 0, int imaginaryPart = 0)     // Defines a constructor with two parameters
        : real(realPart), imaginary(imaginaryPart)      // Initializes real and imaginary variables
    {
    }

    Complex operator+(const Complex& other) const        // Overloads the binary + operator
    {
        return Complex(real + other.real,               // Adds the real parts of two complex numbers
                       imaginary + other.imaginary);    // Adds the imaginary parts of two complex numbers
    }

    void display() const                                  // Defines a function to display the complex number
    {
        std::cout << real;                                // Displays the real part

        if (imaginary >= 0)                               // Checks whether imaginary part is positive or zero
        {
            std::cout << " + ";                           // Displays the plus sign
        }
        else                                              // Executes when imaginary part is negative
        {
            std::cout << " - ";                           // Displays the minus sign
        }

        std::cout << (imaginary >= 0 ? imaginary : -imaginary) // Gets positive value for display
                  << "i\n";                               // Displays i and moves to the next line
    }
};

int main()                                              // Main function where program execution starts
{
    Complex first(2, 3);                                // Creates first complex number 2 + 3i

    Complex second(4, 5);                               // Creates second complex number 4 + 5i

    Complex sum = first + second;                       // Adds first and second using overloaded + operator

    std::cout << "First complex number: ";              // Displays message for first number

    first.display();                                    // Displays the first complex number

    std::cout << "Second complex number: ";             // Displays message for second number

    second.display();                                   // Displays the second complex number

    std::cout << "Sum: ";                               // Displays message for the result

    sum.display();                                      // Displays the sum of two complex numbers

    return 0;                                           // Returns 0 to indicate successful execution
}