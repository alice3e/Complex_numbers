//main.cpp

#include "basic_operations.h"

int main() {
    setlocale(LC_ALL, "Russian");
    // ARRAY INPUT
    Basic_operations::test_function();
    Basic_operations::Complex x(5,7);
    Basic_operations::Complex y(2,4);
    std::cout << "x:    "<< x.Normal_form() << std::endl;     // WORKS
    std::cout << "y:    "<< y.Normal_form() << std::endl;     // WORKS
    std::cout << "x+y:  " << (x+y).Normal_form() << std::endl;// WORKS
    std::cout << "x-y:  "<< (x-y).Normal_form() << std::endl; // WORKS
    std::cout << "x*y:  "<< (x*y).Normal_form() << std::endl; // WORKS
    std::cout << "x/y:  "<< (x/y).Normal_form() << std::endl; // WORKS
    std::cout << "x*x*x:  "<< (x*x*x).Normal_form() << std::endl; // WORKS
    std::cout << "not(x):  "<< (x.conjugate()).Normal_form() << std::endl; // WORKS
    // НЕ РАБОТАЕТ!!!
    //Basic_operations::Complex z = Basic_operations::Complex::pow(x,3);
    std::cout << "End of test section" << std::endl;
}
