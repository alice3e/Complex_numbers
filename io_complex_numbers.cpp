#include "io_complex_numbers.h"

#include <iostream>

BasicOperations::Complex x(-4,0);
BasicOperations::Complex y(-2,1);

int IOComplex::get_user_menu_action() {
    std::cout << std::endl;
    show_menu();
    int answer;
    std::cin >> answer;
    std::cout << std::endl;
    return answer;
}

void IOComplex::print_example_result(
    const char* const comment,
    const BasicOperations::Complex& result
) {
    const char format[] = " = ";
    std::cout << comment << format << result.Normal_form() << std::endl;
}

void IOComplex::process_menu_action() {
    print_example_result("x", x);
    print_example_result("y", y);

    int answer;
    do {
        answer = get_user_menu_action();
        switch (answer) {
            case 0:
                break;
            case 1:
                print_example_result("x + y", x + y);
                break;
            case 2:
                print_example_result("x - y", x - y);
                break;
            case 3:
                print_example_result("x * y", x * y);
                break;
            case 4:
                print_example_result("x / y", x / y);
                break;
            default:
                break;
        }
    } while(answer != 0);
}

void IOComplex::show_menu() {
    std::wcout << L"1 - Сложить\n"
               << L"2 - Вычесть\n"
               << L"3 - Умножить\n"
               << L"4 - Разделить\n"
               << L"0 - Выход из программы\n"
               << L"> ";
}
