#include "iocomplex.h"
#include "assy_complex.h"

ASSY::Complex x(-4,0);
ASSY::Complex y(-2,1);

int IOComplex::menu() {
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

void IOComplex::main_console() {
    std::cout << "x:    "<< x.to_string() << std::endl;
    std::cout << "y:    "<< y.to_string()<< std::endl;
    int ans;
    while(ans != 0) {
        ans = menu();
        switch (ans) {
            case 0:
                break;
            case 1:
                std::cout << "x+y:  " << (x + y).to_string() << std::endl;
                break;
            case 2:
                std::cout << "x-y:  " << (x - y).to_string() << std::endl;
                break;
            case 3:
                std::cout << "x*y:  " << (x * y).to_string() << std::endl;
                break;
            case 4:
                std::cout << "x/y:  " << (x / y).to_string() << std::endl;
                break;

        }
    }
}