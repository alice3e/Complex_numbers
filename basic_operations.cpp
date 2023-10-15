#include "basic_operations.h"

// Эта функция будет автоматически вызываться при создании обьекта класса
// В будущем можно сдесь различные проверки или автоматический перевод в Триг. форму сделать
BasicOperations::Complex::Complex(double x, double y) {
    Rez = x;
    Imz = y;
    // TODO: перевод в поляную систему доделать.
    radius = sqrt( (std::pow(x,2) + std::pow(y,2) ) );
    sin_theta = sin(Rez/radius);
    cos_theta = sin(Imz/radius);
    theta_asin = std::asin(sin_theta);
    if(cos_theta < 0) theta_asin += 0.5;
    while(theta_asin < 0) theta_asin += 2; // Чтобы всегда положительный  угол был
    theta = fmod(theta_asin,(2*M_PI)); // Остаток от деления на 2*Pi
    angle = (theta*180)/M_PI;
}

double BasicOperations::Complex::GetImz() const {
    return Imz;
}

double BasicOperations::Complex::GetReZ() const {
    return Rez;
}

double BasicOperations::Complex::GetTheta() const {
    return theta;
}

double BasicOperations::Complex::GetAngle() const {
    return angle;
}

double BasicOperations::Complex::GetSin() const {
    return sin_theta;
}

double BasicOperations::Complex::GetCos() const {
    return cos_theta;
}

std::string BasicOperations::Complex::Normal_form() const {
    double x = Rez, y = Imz;
    std::string out, sig;
    std::string xstr = std::to_string(x), ystr = std::to_string(y);
    y >= 0 ? sig = '+' : sig = '-';

    std::string yline, xline;
    int n = xstr.size(), m = ystr.size();
    for (int i = 0; i < n; ++i) {
        if (xstr[i] == '.') {
            n = i + 3;
        }
        if (xstr[i] == '.' && xstr[i + 1] == '0') {
            break;
        }
        xline += xstr[i];
    }
    for (int i = 0; i < m; ++i) {
        if (ystr[i] == '.') {
            m = i + 3;
        }
        if (ystr[i] == '.' && ystr[i + 1] == '0') {
            break;
        }
        if (ystr[i] != '-') {
            yline += ystr[i];
        }
    }

    out += "(" + xline + " " + sig + " " + yline + "i)";

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

