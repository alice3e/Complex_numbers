//main.cpp

#include "basic_operations.h"

int main() {
    setlocale(LC_ALL, "Russian");
    // ARRAY INPUT
    BasicOperations::Complex x(-4,0);
    BasicOperations::Complex y(-2,1);
    std::cout << "x:    "<< x.Normal_form() << std::endl;     // WORKS
    std::cout << "x_theta :    "<< x.GetTheta() << std::endl;     // WORKS
    std::cout << "x_angle :    "<< x.GetAngle() << std::endl;     // WORKS
    std::cout << "x_cos & x_sin: "<< x.GetCos() << "  " << x.GetSin() << std::endl;
    std::cout << "y:    "<< y.Normal_form() << std::endl;     // WORKS
    std::cout << "y_theta :    "<< y.GetTheta() << std::endl;     // WORKS
    std::cout << "y_angle :    "<< y.GetAngle() << std::endl;     // WORKS
    std::cout << "y_cos & y_sin: "<< y.GetCos() << "  " << y.GetSin() << std::endl;
    std::cout << "x+y:  " << (x+y).Normal_form() << std::endl;// WORKS
    std::cout << "x-y:  "<< (x-y).Normal_form() << std::endl; // WORKS
    std::cout << "x*y:  "<< (x*y).Normal_form() << std::endl; // WORKS
    std::cout << "x/y:  "<< (x/y).Normal_form() << std::endl; // WORKS
    std::cout << "x*x*x:  "<< (x*x*x).Normal_form() << std::endl; // WORKS
    std::cout << "x^3:  "<< (x.pow(3)).Normal_form() << std::endl; // WORKS !
    std::cout << "not(x):  "<< (x.conjugate()).Normal_form() << std::endl; // WORKS
    std::cout << "End of test section" << std::endl;
}
