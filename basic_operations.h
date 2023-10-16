#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include<iomanip>

namespace BasicOperations{

    class Complex{
    private:
        // Cartesian plane
        double Rez;
        double Imz;
        // Polar coordinates
        double radius;
        double theta; // radians (0 - 2Pi)
        double angle; // degrees (0 - 360)
        double sin_theta;
        double cos_theta;
        double theta_asin;

    public:
        Complex(double x = 1, double y = 0); // объявляем конструктор по умолчанию просто 1


        // Объявляем 2 функции для чтения полей и для красивого вывода числа (x;iy)
        //[[nodiscard]] - Этот атрибут используется, чтобы обозначить, что возвращаемое значение функции должно быть обязательно использовано при вызове:
        [[nodiscard]] double GetReZ() const;
        [[nodiscard]] double GetImz() const;
        [[nodiscard]] double GetTheta() const;
        [[nodiscard]] double GetAngle() const;
        [[nodiscard]] double GetSin() const;
        [[nodiscard]] double GetCos() const;
        [[nodiscard]] std::string Normal_form() const;

        // Простейшие операции
        Complex operator+(const Complex& x) const;
        Complex operator-(const Complex& x) const;
        Complex operator*(const Complex& x) const;
        Complex operator/(const Complex& x) const;
        [[nodiscard]] BasicOperations::Complex pow(int n); // Возведение в степень x.pow(3) -> x^3
        [[nodiscard]] BasicOperations::Complex sqrt();
        Complex conjugate() const; // Комплексно сопряженное
    };
}