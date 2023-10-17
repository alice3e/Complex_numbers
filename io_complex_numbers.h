#pragma once

#include "basic_operations.h"

namespace IOComplex {
    int get_user_main_menu_action();
    int get_user_arithm_menu_action();
    int get_user_x_menu_action();
    int get_user_y_menu_action();
    void print_example_result(
        const char* const comment,
        const TFCV::Complex& result
    );
    void process_menu_action();
    void show_main_menu();
    void show_arithm_menu();
    void show_x_menu();
    void show_y_menu();
}
