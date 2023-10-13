#include<iomanip>

#include "basic_operations.h"

// Эта функция будет автоматически вызываться при создании обьекта класса
// В будущем можно сдесь различные проверки или автоматический перевод в Триг. форму сделать
BasicOperations::Complex::Complex(double x, double y) {
    Rez = x;
    Imz = y;
    // TODO: перевод в поляную систему доделать.
    radius = sqrt( (std::pow(x,2) + std::pow(y,2) ) );
    double sin_thetha = sin(radius/Rez);
    double cos_thetha = sin(radius/Rez);

}

double BasicOperations::Complex::GetImz() const {
    return Imz;
}

double BasicOperations::Complex::GetReZ() const {
    return Rez;
}

std::string BasicOperations::Complex::Normal_form() const {
    std::string out;
    double x = Rez, y = Imz;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);
    // TODO: Сделать вывод числа без нулей округленное до 3х знаков
    if (x - int(x) == 0 && y - int(y) == 0){
        if (y >= 0) {
            out += "(" + std::to_string(int(x)) + " + " + std::to_string(int(y)) + "i)";
        } else {
            out += "(" + std::to_string(int(x)) + " - " + std::to_string(int(y) * -1) + "i)";
        }
    } else {
        if (y >= 0) {
            out += "(" + std::to_string(x) + " + " + std::to_string(y) + "i)";
        } else {
            out += "(" + std::to_string(x) + " - " + std::to_string(y * -1) + "i)";
        }
    }
    return out;
}

BasicOperations::Complex BasicOperations::Complex::operator+(const BasicOperations::Complex &x) const {
    return BasicOperations::Complex{Rez+x.Rez,Imz+x.Imz};
}

BasicOperations::Complex BasicOperations::Complex::operator-(const BasicOperations::Complex &x) const {
    return BasicOperations::Complex{Rez-x.Rez,Imz-x.Imz};
}

BasicOperations::Complex BasicOperations::Complex::operator*(const BasicOperations::Complex &x) const {
    return BasicOperations::Complex{  ((Rez*x.Rez) - (Imz * x.Imz))  ,  ( (Rez*x.Imz) + (Imz * x.Rez) )  };
}

BasicOperations::Complex BasicOperations::Complex::operator/(const BasicOperations::Complex &x) const {
    double denominator = std::pow(x.Rez,2) + std::pow(x.Imz,2); // знаменатель с^2 + d^2
    return BasicOperations::Complex{ (((Rez*x.Rez) + (Imz * x.Imz))/denominator) , ( ( (Imz * x.Rez) - (Rez*x.Imz) )/denominator) };
}

BasicOperations::Complex BasicOperations::Complex::conjugate() const{
    // conjugate == not(z)
    // z + not(z) = Rez(z) ; not(not(z)) = z ; z * not(z) = Rez^2 + Imz^2
    Complex result;
    result.Rez = Rez;
    result.Imz = Imz*(-1);
    return result;
}

BasicOperations::Complex BasicOperations::Complex::pow(int n) {
    Complex result(1, 0);
    bool flag = true;
    if (n == 0) return Complex(1, 0);
    else if (n < 0) {
        n = -n;
        flag = false;
    }
    Complex base(*this);  // Create a copy of the current complex number
    for (int i = 0; i < n; i++) {
        result = result * base;
    }
    if (flag) {
        return result;
    }
    else {
        return Complex(1, 0) / result;
    }
}

