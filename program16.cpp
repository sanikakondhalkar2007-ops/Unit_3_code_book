#include <iostream>                                      // Includes the iostream library for input and output
#include <string>                                        // Includes the string library for storing names
#include <utility>                                       // Includes utility library for std::move

class Employee                                             // Defines the abstract base class Employee
{
protected:                                                 // Starts the protected section of Employee

    int employeeId;                                        // Stores the employee ID

    std::string name;                                      // Stores the employee name

public:                                                    // Starts the public section of Employee

    Employee(int id, std::string employeeName)             // Defines the Employee constructor
        : employeeId(id), name(std::move(employeeName))   // Initializes employeeId and name
    {
    }

    virtual double calculateSalary() const = 0;            // Declares pure virtual function for salary calculation

    void displayBasicDetails() const                       // Defines a function to display basic employee details
    {
        std::cout << "Employee ID: " << employeeId << '\n'; // Displays the employee ID

        std::cout << "Name: " << name << '\n';             // Displays the employee name
    }

    virtual ~Employee() = default;                         // Defines a virtual destructor
};

class PermanentEmployee : public Employee                  // Defines PermanentEmployee inheriting from Employee
{
private:                                                   // Starts the private section of PermanentEmployee

    double basicSalary;                                    // Stores the basic salary

    double allowance;                                      // Stores the additional allowance

public:                                                    // Starts the public section of PermanentEmployee

    PermanentEmployee(int id, std::string employeeName, double basic, double extra) // Defines constructor
        : Employee(id, std::move(employeeName)),            // Calls the Employee constructor
          basicSalary(basic), allowance(extra)              // Initializes basic salary and allowance
    {
    }

    double calculateSalary() const override                 // Overrides calculateSalary() for permanent employee
    {
        return basicSalary + allowance;                     // Returns basic salary plus allowance
    }
};

class ContractEmployee : public Employee                    // Defines ContractEmployee inheriting from Employee
{
private:                                                   // Starts the private section of ContractEmployee

    double hourlyRate;                                     // Stores the payment rate per hour

    int hoursWorked;                                       // Stores the number of hours worked

public:                                                    // Starts the public section of ContractEmployee

    ContractEmployee(int id, std::string employeeName, double rate, int hours) // Defines constructor
        : Employee(id, std::move(employeeName)),            // Calls the Employee constructor
          hourlyRate(rate), hoursWorked(hours)               // Initializes hourly rate and hours worked
    {
    }

    double calculateSalary() const override                 // Overrides calculateSalary() for contract employee
    {
        return hourlyRate * hoursWorked;                    // Returns hourly rate multiplied by hours worked
    }
};

void printPaySlip(const Employee& employee)                 // Defines a function to print employee pay slip
{
    employee.displayBasicDetails();                         // Displays basic employee details

    std::cout << "Salary: Rs. " << employee.calculateSalary() << "\n\n"; // Calculates and displays salary
}

int main()                                                 // Main function where program execution starts
{
    PermanentEmployee permanentEmployee(101, "Asha", 40000.0, 8000.0); // Creates permanent employee object

    ContractEmployee contractEmployee(102, "Vikas", 500.0, 80);       // Creates contract employee object

    printPaySlip(permanentEmployee);                        // Prints salary details of permanent employee

    printPaySlip(contractEmployee);                         // Prints salary details of contract employee

    return 0;                                               // Returns 0 to indicate successful execution
}