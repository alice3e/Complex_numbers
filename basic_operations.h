//
// Created by alicee on 13.10.2023.
//
#pragma once
#include <iostream>
#include <string>
#include <math.h>
namespace Basic_operations{
    void test_function();

    class Complex{
    private:
        // Cartesian plane
        double Rez;
        double Imz;
        // Polar coordinates
        double radius;
        double angle;

    public:
        Complex(double x, double y); // объявляем конструктор

        // Объявляем 2 функции для чтения полей и для красивого вывода числа (x;iy)
        //[[nodiscard]] - Этот атрибут используется, чтобы обозначить, что возвращаемое значение функции должно быть обязательно использовано при вызове:
        [[nodiscard]] double GetReZ() const;
        [[nodiscard]] double GetImz() const;
        [[nodiscard]] std::string Normal_form() const;

        // Простейшие операции
        Complex operator+(const Complex& x) const;
        Complex operator-(const Complex& x) const;
        Complex operator*(const Complex& x) const;
        Complex operator/(const Complex& x) const;
    };
}