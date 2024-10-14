#include <iostream>
#include <sstream>
#include <string>

int main() {
    // 1
    std::string input = "123 456 789";
    std::stringstream ss(input);
    int a, b, c;
    ss >> a >> b >> c;
    std::cout << "Parsed numbers: " << a << ", " << b << ", " << c << std::endl;
    // Output: Parsed numbers: 123, 456, 789

    // 2
    std::string input2;
    getline(std::cin, input2);
    char slash;
    int day, month, year;
    
    std::stringstream ss2(input2);
    ss2 >> day >> slash >> month >> slash >> year;

    std::cout << "The date today is " << year << "." << month << "." << day;


    return 0;
}