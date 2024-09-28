#include <iostream>
#include <map>
#include <cmath>
#include <string>

// Function to convert string from a given base to decimal
int baseToDecimal(const std::string &value, int base) {
    int result = 0, power = 0;
    for (int i = value.length() - 1; i >= 0; i--) {
        char c = value[i];
        int digit = (isdigit(c)) ? c - '0' : toupper(c) - 'A' + 10;
        result += digit * pow(base, power++);
    }
    return result;
}

// Lagrange Interpolation to find constant term (c)
double lagrangeInterpolation(const std::map<int, int> &points) {
    double result = 0.0;
    for (auto &p1 : points) {
        double term = p1.second; // f(xi)
        for (auto &p2 : points) {
            if (p1.first != p2.first) {
                term *= (0.0 - p2.first) / (p1.first - p2.first); // Multiply by (x - xj) / (xi - xj)
            }
        }
        result += term;
    }
    return result;
}

int main() {
    // Input data from problem
    std::map<int, std::pair<int, std::string>> input = {
        {1, {10, "4"}},   // base 10
        {2, {2, "111"}},  // base 2
        {3, {10, "12"}},  // base 10
        {6, {4, "213"}}   // base 4
    };

    // Convert the input to (x, f(x)) in decimal form
    std::map<int, int> points;
    for (const auto &p : input) {
        int x = p.first;
        int base = p.second.first;
        std::string value = p.second.second;
        points[x] = baseToDecimal(value, base);
    }

    // Calculate the constant term using Lagrange Interpolation
    double c = lagrangeInterpolation(points);

    std::cout << "The constant term c is: " << c << std::endl;
    return 0;
}
