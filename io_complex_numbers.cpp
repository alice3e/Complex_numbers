#include "io_complex_numbers.h"
#include "basic_operations.h"

BasicOperations::Complex x(-4,0);
BasicOperations::Complex y(-2,1);

int IOComplexNumbers::menu() {
    int answer;
    std::cout << "\n1 - Сложить\n"
         << "2 - Вычесть\n"
         << "3 - Умножить\n"
         << "4 - Разделить\n"
         << "0 - Выход из программы\n"
         << "> ";
    std::cin >> answer;
    std::cout << std::endl;
    return answer;
}

void IOComplexNumbers::main_console() {
    std::cout << "x:    "<< x.Normal_form() << std::endl;
    std::cout << "y:    "<< y.Normal_form() << std::endl;
    int ans;
    while(ans != 0) {
        ans = menu();
        switch (ans) {
            case 0:
                break;
            case 1:
                std::cout << "x+y:  " << (x + y).Normal_form() << std::endl;
                break;
            case 2:
                std::cout << "x-y:  " << (x - y).Normal_form() << std::endl;
                break;
            case 3:
                std::cout << "x*y:  " << (x * y).Normal_form() << std::endl;
                break;
            case 4:
                std::cout << "x/y:  " << (x / y).Normal_form() << std::endl;
                break;

        }
    }
}