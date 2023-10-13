//
// Created by alicee on 13.10.2023.
//
#include "basic_operations.h"

void Basic_operations::test_function() {
    std::cout << "Hello from namespace basic_operations" << std::endl;
}

// Эта функция будет автоматически вызываться при создании обьекта класса
// В будущем можно сдесь различные проверки или автоматический перевод в Триг. форму сделать
Basic_operations::Complex::Complex(int x, int y) {
    Rez = x;
    Imz = y;
}

int Basic_operations::Complex::GetImz() const {
    return Imz;
}

int Basic_operations::Complex::GetReZ() const {
    return Rez;
}

std::string Basic_operations::Complex::Normal_form() const {
    std::string out;
    if(Imz > 0){
        out += "(" + std::to_string(Rez) + " + " + std::to_string(Imz) + "i)";
    }else{
        out += "(" + std::to_string(Rez) + " - " + std::to_string(Imz*-1) + "i)";
    }
    return out;
}

Basic_operations::Complex Basic_operations::Complex::operator+(const Basic_operations::Complex &x) const {
    return Basic_operations::Complex{Rez+x.Rez,Imz+x.Imz};
}

Basic_operations::Complex Basic_operations::Complex::operator-(const Basic_operations::Complex &x) const {
    return Basic_operations::Complex{Rez-x.Rez,Imz-x.Imz};
}