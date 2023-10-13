//main.cpp

#include "basic_operations.h"

int main() {
    setlocale(LC_ALL, "Russian");
    // ARRAY INPUT
    Basic_operations::test_function();
    Basic_operations::Complex x(1,3);
    Basic_operations::Complex y(2,4);
    std::cout << x.Normal_form() << std::endl;
    std::cout << y.Normal_form() << std::endl;
    std::cout << (x+y).Normal_form() << std::endl;
    std::cout << (x-y).Normal_form() << std::endl;

}
