#include <iostream>                                      // Includes the iostream library for input and output

class Distance                                            // Defines a class named Distance
{
private:                                                  // Starts the private section of the class

    int meters;                                           // Declares a variable to store distance in meters

public:                                                   // Starts the public section of the class

    explicit Distance(int value) : meters(value)         // Defines a constructor and initializes meters
    {
    }

    bool operator>(const Distance& other) const           // Overloads the greater-than > operator
    {
        return meters > other.meters;                     // Compares the meters of two objects
    }

    void display() const                                  // Defines a function to display the distance
    {
        std::cout << meters << " meters\n";               // Displays the distance in meters
    }
};

int main()                                              // Main function where program execution starts
{
    Distance first(120);                                // Creates first Distance object with 120 meters

    Distance second(90);                                // Creates second Distance object with 90 meters

    std::cout << "First distance: ";                    // Displays message for first distance

    first.display();                                    // Displays the first distance

    std::cout << "Second distance: ";                   // Displays message for second distance

    second.display();                                   // Displays the second distance

    if (first > second)                                 // Uses overloaded > operator to compare distances
    {
        std::cout << "First distance is greater\n";     // Displays this message if first is greater
    }
    else                                                // Executes when first is not greater
    {
        std::cout << "Second distance is greater or equal\n"; // Displays the alternative message
    }

    return 0;                                           // Returns 0 to indicate successful execution
}