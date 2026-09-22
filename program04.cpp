#include <iostream>                         // Includes the iostream library for input and output

class Counter                                // Defines a class named Counter
{
private:                                     // Starts the private section of the class

    int value;                               // Declares an integer variable to store counter value

public:                                      // Starts the public section of the class

    explicit Counter(int initialValue = 0)   // Defines a constructor with a default value of 0
        : value(initialValue)               // Initializes value using initialValue
    {
    }

    Counter& operator++()                    // Overloads the prefix increment operator
    {
        ++value;                             // Increases the value by 1
        return *this;                        // Returns the updated current object
    }

    Counter operator++(int)                  // Overloads the postfix increment operator
    {
        Counter old = *this;                 // Creates a copy containing the old value

        ++value;                             // Increases the actual counter value by 1

        return old;                          // Returns the old value
    }

    void display() const                     // Defines a function to display counter value
    {
        std::cout << value << '\n';          // Displays the current counter value
    }
};

int main()                                  // Main function where program execution starts
{
    Counter counter(5);                      // Creates a Counter object with initial value 5

    std::cout << "After prefix increment: "; // Displays the prefix increment message

    ++counter;                               // Performs prefix increment before using the value

    counter.display();                       // Displays the updated value

    std::cout << "Value returned by postfix increment: "; // Displays the postfix message

    Counter oldValue = counter++;            // Stores old value and then increments counter

    oldValue.display();                      // Displays the old value returned by postfix increment

    std::cout << "Counter after postfix increment: "; // Displays the final counter message

    counter.display();                       // Displays the final counter value

    return 0;                                // Returns 0 to indicate successful execution
}