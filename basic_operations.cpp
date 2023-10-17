#include "basic_operations.h"

TFCV::Complex::Complex(double x, double y) {
    // TODO: Нет проверки на ошибки входных данных
    re = x;
    im = y;

    // TODO: перевод в поляную систему доделать.
    radius = std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    sin_theta = sin(re / radius);
    cos_theta = sin(im / radius);
    theta_asin = std::asin(sin_theta);

    if (cos_theta < 0) {
        theta_asin += 0.5;
    }
    while (theta_asin < 0) {
        // Рассматриваем всегда положительный угол
        theta_asin += 2;
    }

    theta = fmod(theta_asin, 2 * M_PI);
    angle = (theta * 180) / M_PI;
}

double TFCV::Complex::get_im() const { return im; }
double TFCV::Complex::get_re() const { return re; }
double TFCV::Complex::get_theta() const { return theta; }
double TFCV::Complex::get_angle() const { return angle; }
double TFCV::Complex::get_sin() const { return sin_theta; }
double TFCV::Complex::get_cos() const { return cos_theta; }

std::string TFCV::Complex::to_string() const {
    std::string xstr = std::to_string(re);
    std::string ystr = std::to_string(im);
    int n = xstr.size();
    int m = ystr.size();
    std::string xline, yline;

    const char dot = '.';
    const char minus = '-';
    const char plus = '+';
    const char zero = '0';

    for (int i = 0; i < n; ++i) {
        if (xstr[i] == dot) {
            n = i + 3;
        }
        if (xstr[i] == dot && xstr[i + 1] == zero) {
            break;
        }
        xline += xstr[i];
    }

    for (int i = 0; i < m; ++i) {
        if (ystr[i] == dot) {
            m = i + 3;
        }
        if (ystr[i] == dot && ystr[i + 1] == zero) {
            break;
        }
        if (ystr[i] != minus) {
            yline += ystr[i];
        }
    }

    const char sig = im >= 0 ? plus : minus;
    const char space = ' ';

    return "(" + xline + space + sig + space + yline + "i)";
}

TFCV::Complex TFCV::Complex::operator + (const TFCV::Complex &z) const {
    return {re + z.re, im + z.im};
}

TFCV::Complex TFCV::Complex::operator - (const TFCV::Complex &z) const {
    return {re - z.re, im - z.im};
}

TFCV::Complex TFCV::Complex::operator * (const TFCV::Complex &z) const {
    return {re * z.re - im * z.im, re * z.im + im * z.re};
}

TFCV::Complex TFCV::Complex::operator / (const TFCV::Complex &z) const {
    // знаменатель = с^2 + d^2
    const double denominator = std::pow(z.re, 2) + std::pow(z.im, 2);
    const double x = (re * z.re + im * z.im) / denominator;
    const double y = (im * z.re - re * z.im) / denominator;
    return {x, y};
}

TFCV::Complex TFCV::conjugate(const Complex &z) {
    return {z.get_re(), -z.get_im()};
}

TFCV::Complex TFCV::pow(const Complex &z, int n) {
    Complex result(1, 0);
    bool flag = true;

    if (n == 0) return {1, 0};
    else if (n < 0) {
        n = -n;
        flag = false;
    }

    Complex base(z);
    for (int i = 0; i < n; i++) {
        result = result * base;
    }

    if (flag) {
        return result;
    } else {
        return Complex(1, 0) / result;
    }
}
