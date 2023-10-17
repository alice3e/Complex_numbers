#pragma once

#include "basic_operations.h"

namespace IOComplex {
    int get_user_menu_action();
    void print_example_result(
        const char* const comment,
        const BasicOperations::Complex& result
    );
    void process_menu_action();
    void show_menu();
}
