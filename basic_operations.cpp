//
// Created by alicee on 13.10.2023.
//
#include "basic_operations.h"

void Basic_operations::test_function() {
    std::cout << "Hello from namespace basic_operations" << std::endl;
}

// Эта функция будет автоматически вызываться при создании обьекта класса
// В будущем можно сдесь различные проверки или автоматический перевод в Триг. форму сделать
Basic_operations::Complex::Complex(double x, double y) {
    Rez = x;
    Imz = y;
    // TODO: перевод в поляную систему доделать.
    radius = sqrt( (pow(x,2) + pow(y,2) ) );
    double sin_thetha = sin(radius/Rez);
    double cos_thetha = sin(radius/Rez);

}

double Basic_operations::Complex::GetImz() const {
    return Imz;
}

double Basic_operations::Complex::GetReZ() const {
    return Rez;
}

std::string Basic_operations::Complex::Normal_form() const {
    std::string out;
    double x = Rez,y = Imz;

    // TODO: Сделать вывод числа без нулей если оно целое + округление до 3ех знаков
    if(y > 0){
        out += "(" + std::to_string(x) + " + " + std::to_string(y) + "i)";
    }else{
        out += "(" + std::to_string(x) + " - " + std::to_string(y*-1) + "i)";
    }
    return out;
}

Basic_operations::Complex Basic_operations::Complex::operator+(const Basic_operations::Complex &x) const {
    return Basic_operations::Complex{Rez+x.Rez,Imz+x.Imz};
}

Basic_operations::Complex Basic_operations::Complex::operator-(const Basic_operations::Complex &x) const {
    return Basic_operations::Complex{Rez-x.Rez,Imz-x.Imz};
}

Basic_operations::Complex Basic_operations::Complex::operator*(const Basic_operations::Complex &x) const {
    return Basic_operations::Complex{  ((Rez*x.Rez) - (Imz * x.Imz))  ,  ( (Rez*x.Imz) + (Imz * x.Rez) )  };
}
Basic_operations::Complex Basic_operations::Complex::operator/(const Basic_operations::Complex &x) const {
    double denominator = pow(x.Rez,2) + pow(x.Imz,2); // знаменатель с^2 + d^2
    return Basic_operations::Complex{ (((Rez*x.Rez) + (Imz * x.Imz))/denominator) , ( ( (Imz * x.Rez) - (Rez*x.Imz) )/denominator) };
}