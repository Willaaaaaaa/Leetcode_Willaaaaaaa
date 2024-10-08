#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input = "123 456 789";
    std::stringstream ss(input);
    int a, b, c;
    ss >> a >> b >> c;
    std::cout << "Parsed numbers: " << a << ", " << b << ", " << c << std::endl; // Output: Parsed numbers: 123, 456, 789

    return 0;
}