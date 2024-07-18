#include <iostream>
#include <string>

class Employee {
protected:
    std::string m_EmployeeName;

public:
    Employee(std::string& name) : m_EmployeeName(name) {}

    virtual double calculatePay() const = 0;
    virtual void displayInfo() const = 0;
};

class SalariedEmployee : public Employee {
private:
    int yearlySalary;

public:
    SalariedEmployee(std::string name, int salary) : Employee(name), yearlySalary(salary) {}

    double calculatePay() const override {
        return yearlySalary / 12;
    }

    void displayInfo() const override {
        std::cout << "Salaried Employee: " << m_EmployeeName << ". Monthly Salary: " << calculatePay() << "\n";
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyPay;
    int hoursWorked;

public:
    HourlyEmployee(std::string name, double pay, int hours) : Employee(name), hourlyPay(pay), hoursWorked(hours) {}

    double calculatePay() const override {
        return hourlyPay * hoursWorked;
    }

    void displayInfo() const override {
        std::cout << "Hourly Employee: " << m_EmployeeName << ". Weekly Salary: " << calculatePay() << "\n";
    }
};

int main() {
    SalariedEmployee salariedEmployee("Thomas", 30000);
    HourlyEmployee hourlyEmployee("Gibby", 70, 40);

    salariedEmployee.displayInfo();
    hourlyEmployee.displayInfo();
}