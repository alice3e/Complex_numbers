#pragma once

#include "basic_operations.h"

namespace IOComplex {
//    void input();
//    int get_user_menu_action();
    int get_user_main_menu_action();
    int get_user_arithm_menu_action();
    int get_user_number_menu_action(
            const char* const comment,
            const char* const last_section
    );
    void print_example_result(
        const char* const comment,
        const TFCV::Complex& result
    );
    void process_menu_action();
    void show_main_menu();
    void show_arithm_menu();
    void show_number_menu(
        const char* const comment,
        const char* const last_section
    );

}

