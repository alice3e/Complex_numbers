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
    radius = sqrt( (std::pow(x,2) + std::pow(y,2) ) );
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
    if(y >= 0){
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
    double denominator = std::pow(x.Rez,2) + std::pow(x.Imz,2); // знаменатель с^2 + d^2
    return Basic_operations::Complex{ (((Rez*x.Rez) + (Imz * x.Imz))/denominator) , ( ( (Imz * x.Rez) - (Rez*x.Imz) )/denominator) };
}

Basic_operations::Complex Basic_operations::Complex::conjugate() const{
    // conjugate == not(z)
    // z + not(z) = Rez(z) ; not(not(z)) = z ; z * not(z) = Rez^2 + Imz^2
    Complex result;
    result.Rez = Rez;
    result.Imz = Imz*(-1);
    return result;
}


// ERROR!!! НЕ РАБОТАЕТ!

/*
Basic_operations::Complex Basic_operations::Complex::pow(const Basic_operations::Complex &x, int n) const {
    // TODO: СДЕЛАТЬ БИНАРНОЕ ВОЗВЕДЕНИЕ В СТЕПЕНЬ ЧИСЛА
    Complex result(1,0);
    bool flag = true;
    if(n==0) return Complex(0,0);
    else if(n<0){
        n = -1*n;
        flag = false;
    }
    for(int i = 0;i < n; i++){
        result = result * x;
    }
    if(flag){
        return result;
    }else{
        return (Complex(1,0)/result);
    }
}
*/