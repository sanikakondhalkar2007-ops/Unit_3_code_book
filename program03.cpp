#include <iostream>                         // Includes the iostream library for input and output

class Number                                 // Defines a class named Number
{
private:                                     // Starts the private section of the class

    int value;                               // Declares an integer variable to store the number

public:                                      // Starts the public section of the class

    explicit Number(int givenValue)          // Defines a constructor that accepts an integer value
        : value(givenValue)                  // Initializes the value variable using givenValue
    {
    }

    Number operator-() const                 // Overloads the unary minus (-) operator
    {
        return Number(-value);               // Returns a new Number object with a negative value
    }

    void display() const                     // Defines a function to display the stored value
    {
        std::cout << value << '\n';          // Displays the value on the screen
    }
};

int main()                                  // Main function where program execution starts
{
    Number first(25);                        // Creates a Number object named first with value 25

    Number second = -first;                  // Applies unary minus operator to first and stores the result

    std::cout << "Original value: ";         // Displays a message for the original value

    first.display();                         // Calls display() to show the original value

    std::cout << "Negated value: ";          // Displays a message for the negative value

    second.display();                        // Calls display() to show the negative value

    return 0;                                // Returns 0 to indicate successful execution
}