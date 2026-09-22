#include <iostream>                                      // Includes the iostream library for input and output

class Complex                                             // Defines a class named Complex
{
private:                                                  // Starts the private section of the class

    int real;                                             // Declares a variable to store the real part

    int imaginary;                                        // Declares a variable to store the imaginary part

public:                                                   // Starts the public section of the class

    Complex(int realPart = 0, int imaginaryPart = 0)     // Defines a constructor
        : real(realPart), imaginary(imaginaryPart)      // Initializes real and imaginary variables
    {
    }

    friend Complex operator+(int value,                  // Declares operator+ as a friend function
                             const Complex& number);     // Allows the function to access private members

    void display() const                                  // Defines a function to display the complex number
    {
        std::cout << real;                                // Displays the real part

        if (imaginary >= 0)                               // Checks if imaginary part is positive or zero
        {
            std::cout << " + ";                           // Displays plus sign
        }
        else                                              // Executes when imaginary part is negative
        {
            std::cout << " - ";                           // Displays minus sign
        }

        std::cout << (imaginary >= 0 ? imaginary : -imaginary) // Displays the absolute imaginary value
                  << "i\n";                               // Displays i and moves to the next line
    }
};

Complex operator+(int value, const Complex& number)      // Defines the friend operator+ function
{
    return Complex(value + number.real,                  // Adds integer value to the real part
                   number.imaginary);                    // Keeps the imaginary part unchanged
}

int main()                                              // Main function where program execution starts
{
    Complex number(2, 3);                                // Creates a Complex object with value 2 + 3i

    Complex result = 10 + number;                        // Adds integer 10 to the complex number

    std::cout << "Result: ";                             // Displays the result message

    result.display();                                    // Displays the resulting complex number

    return 0;                                           // Returns 0 to indicate successful execution
}