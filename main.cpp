//main.cpp

#include "basic_operations.h"

int main() {
    setlocale(LC_ALL, "Russian");
    // ARRAY INPUT
    BasicOperations::Complex x(5,7);
    BasicOperations::Complex y(2,4);
    std::cout << "x:    "<< x.Normal_form() << std::endl;     // WORKS
    std::cout << "y:    "<< y.Normal_form() << std::endl;     // WORKS
    std::cout << "x+y:  " << (x+y).Normal_form() << std::endl;// WORKS
    std::cout << "x-y:  "<< (x-y).Normal_form() << std::endl; // WORKS
    std::cout << "x*y:  "<< (x*y).Normal_form() << std::endl; // WORKS
    std::cout << "x/y:  "<< (x/y).Normal_form() << std::endl; // WORKS
    std::cout << "x*x*x:  "<< (x*x*x).Normal_form() << std::endl; // WORKS
    std::cout << "x^3:  "<< (x.pow(3)).Normal_form() << std::endl; // WORKS !
    std::cout << "not(x):  "<< (x.conjugate()).Normal_form() << std::endl; // WORKS
    std::cout << "End of test section" << std::endl;
}
