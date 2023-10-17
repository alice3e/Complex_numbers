#include "io_complex_numbers.h"

#include <iostream>

TFCV::Complex x(-4,0);
TFCV::Complex y(-2,1);

int IOComplex::get_user_main_menu_action() {
    std::cout << std::endl;
    show_main_menu();
    int answer;
    std::cin >> answer;
    std::cout << std::endl;
    return answer;
}

int IOComplex::get_user_arithm_menu_action() {
    std::cout << std::endl;
    show_arithm_menu();
    int answer;
    std::cin >> answer;
    std::cout << std::endl;
    return answer;
}

int IOComplex::get_user_x_menu_action() {
    std::cout << std::endl;
    show_x_menu();
    int answer;
    std::cin >> answer;
    std::cout << std::endl;
    return answer;
}

int IOComplex::get_user_y_menu_action() {
    std::cout << std::endl;
    show_y_menu();
    int answer;
    std::cin >> answer;
    std::cout << std::endl;
    return answer;
}

void IOComplex::print_example_result(
    const char* const comment,
    const TFCV::Complex& result
) {
    const char format[] = " = ";
    std::cout << comment << format << result.to_string() << std::endl;
}

void IOComplex::process_menu_action() {
    print_example_result("x", x);
    print_example_result("y", y);

    int answer_main;
    int answer_arithm;
    int answer_x;
    int answe_y;
    do {
        answer_main = get_user_main_menu_action();
        switch (answer_main) {
            case 0:
                break;
            case 1:
                do {
                    answer_arithm = get_user_arithm_menu_action();
                    switch (answer_arithm) {
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
                } while(answer_arithm != 0);
            case 2:
                do {
                    answer_x = get_user_x_menu_action();
                    switch (answer_x) {
                        case 0:
                            break;
                        case 1:
                            print_example_result("x", x);
                            break;
                        case 2:
                            std::cout << "x_theta : "<< x.get_theta() << std::endl;
                            break;
                        case 3:
                            std::cout << "x_angle : "<< x.get_angle() << std::endl;
                            break;
                        case 4:
                            std::cout << "x_cos: " << x.get_cos() << std::endl;
                            break;
                        case 5:
                            std::cout << "x_sin: "<< x.get_sin() << std::endl;
                            break;
                        default:
                            break;
                    }
                } while(answer_x != 0);
            case 3:
                do {
                    answe_y = get_user_y_menu_action();
                    switch (answe_y) {
                        case 0:
                            break;
                        case 1:
                            print_example_result("y", x);
                            break;
                        case 2:
                            std::cout << "y_theta : "<< y.get_theta() << std::endl;
                            break;
                        case 3:
                            std::cout << "y_angle : "<< y.get_angle() << std::endl;
                            break;
                        case 4:
                            std::cout << "y_cos: " << y.get_cos() << std::endl;
                            break;
                        case 5:
                            std::cout << "y_sin: "<< y.get_sin() << std::endl;
                            break;
                        default:
                            break;
                    }
                } while(answe_y != 0);
            default:
                break;
        }

    } while (answer_main != 0);
}

void IOComplex::show_main_menu() {
    std::cout << "1 - Арифметические операции\n"
               << "2 - Операции с X\n"
               << "3 - Операции с Y\n"
               << "0 - Выход из программы\n"
               << "> ";
}

void IOComplex::show_arithm_menu() {
    std::cout << "1 - Сложить\n"
              << "2 - Вычесть\n"
              << "3 - Умножить\n"
              << "4 - Разделить\n"
              << "0 - следующий раздел\n"
              << "> ";
}

void IOComplex::show_x_menu() {
    std::cout << "1 - Показать X\n"
              << "2 - Угол Тетта у Х\n"
              << "3 - Угол у Х\n"
              << "4 - Косину Х\n"
              << "5 - Синус Х\n"
              << "0 - следующий раздел\n"
              << "> ";
}

void IOComplex::show_y_menu() {
    std::cout << "1 - Показать Y\n"
              << "2 - Угол Тетта у Y\n"
              << "3 - Угол у Y\n"
              << "4 - Косину Y\n"
              << "5 - Синус Y\n"
              << "0 - Вернуться в главное меню\n"
              << "> ";
}
