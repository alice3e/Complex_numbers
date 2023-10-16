#pragma once

#include <string>

namespace ASSY {

    class Complex {
        private:
            // Cartesian plane
            double re;
            double im;

            // Polar coordinates
            // radians (0 - 2Pi)
            // degrees (0 - 360)
            double radius;
            double theta;
            double angle;

            double sin_theta;
            double cos_theta;
            double theta_asin;

        public:
            Complex(double x, double y);

            // [[nodiscard]] - Этот атрибут используется, чтобы обозначить,
            // что возвращаемое значение функции должно быть обязательно использовано при вызове
            [[nodiscard]] double get_re() const;
            [[nodiscard]] double get_im() const;
            [[nodiscard]] double get_theta() const;
            [[nodiscard]] double get_angle() const;
            [[nodiscard]] double get_sin() const;
            [[nodiscard]] double get_cos() const;
            [[nodiscard]] std::string to_string() const;

            Complex operator + (const Complex& x) const;
            Complex operator - (const Complex& x) const;
            Complex operator * (const Complex& x) const;
            Complex operator / (const Complex& x) const;

            [[nodiscard]] Complex pow(int n);
            // Комплексно сопряженное
            [[nodiscard]] Complex conjugate() const;
    };
}
