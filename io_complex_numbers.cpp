#include "io_complex_numbers.h"

#include <iostream>

TFCV::Complex x(-4,0);
TFCV::Complex y(-2,1);

//void IOComplex::input() {
//    double a, b;
//    std::cout << "a = ";
//    std::cin >> a;
//    std::cout <<  "b = ";
//    std::cin >> b;
//    x = TFCV::Complex(a,b);
//}

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

int IOComplex::get_user_number_menu_action(
    const char *const comment,
    const char *const last_section
) {
    std::cout << std::endl;
    show_number_menu(comment, last_section);
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
//    input();
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
                    answer_x = get_user_number_menu_action("x", "Следующий раздел");
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
                        case 6:
                            std::cout << "Степень n = ";
                            int n; std::cin >> n;
                            print_example_result("x^n", pow(x, n));
                        default:
                            break;
                    }
                } while(answer_x != 0);
            case 3:
                do {
                    answe_y = get_user_number_menu_action("y", "Вернуться в главное меню");
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
                        case 6:
                            std::cout << "Степень n = ";
                            int n; std::cin >> n;
                            print_example_result("y^n", pow(y, n));
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
               << "2 - Операции с x\n"
               << "3 - Операции с y\n"
               << "0 - Выход из программы\n"
               << "> ";
}

void IOComplex::show_arithm_menu() {
    std::cout << "1 - Сложить\n"
              << "2 - Вычесть\n"
              << "3 - Умножить\n"
              << "4 - Разделить\n"
              << "0 - Следующий раздел\n"
              << "> ";
}

void IOComplex::show_number_menu(
        const char *const comment,
        const char* const last_section
) {
    std::cout << "1 - Показать " << comment << '\n'
              << "2 - Угол Θ " << comment << '\n'
              << "3 - Угол в градусах " << comment << '\n'
              << "4 - Косинус " << comment << '\n'
              << "5 - Синус " << comment << '\n'
              << "6 - " << comment << " Возведение в степень n " << '\n'
              << "0 - " << last_section << '\n'
              << "> ";
}
