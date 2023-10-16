#include "assy_complex.h"

#include <cmath>

ASSY::Complex::Complex(double x, double y) {
    // TODO: входные данные считаются корректными
    re = x;
    im = y;

    // TODO: перевод в поляную систему
    radius = sqrt( (std::pow(x,2) + std::pow(y,2) ) );
    sin_theta = sin(re / radius);
    cos_theta = sin(im/radius);
    theta_asin = std::asin(sin_theta);

    if (cos_theta < 0) {
        theta_asin += 0.5;
    }

    while (theta_asin < 0) {
        // Считаем угол всегда положительным
        theta_asin += 2;
    }

    theta = fmod(theta_asin,(2*M_PI));
    angle = (theta*180)/M_PI;
}

double ASSY::Complex::get_im() const {
    return im;
}

double ASSY::Complex::get_re() const {
    return re;
}

double ASSY::Complex::get_theta() const {
    return theta;
}

double ASSY::Complex::get_angle() const {
    return angle;
}

double ASSY::Complex::get_sin() const {
    return sin_theta;
}

double ASSY::Complex::get_cos() const {
    return cos_theta;
}

std::string ASSY::Complex::to_string() const {
    double x = re, y = im;
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

ASSY::Complex ASSY::Complex::operator + (const ASSY::Complex &x) const {
    return ASSY::Complex{re + x.re, im + x.im};
}

ASSY::Complex ASSY::Complex::operator - (const ASSY::Complex &x) const {
    return ASSY::Complex{re - x.re, im - x.im};
}

ASSY::Complex ASSY::Complex::operator * (const ASSY::Complex &x) const {
    return ASSY::Complex{((re * x.re) - (im * x.im))  , ((re * x.im) + (im * x.re) )  };
}

ASSY::Complex ASSY::Complex::operator / (const ASSY::Complex &x) const {
    double denominator = std::pow(x.re, 2) + std::pow(x.im, 2); // знаменатель с^2 + d^2
    return ASSY::Complex{(((re * x.re) + (im * x.im)) / denominator) , (((im * x.re) - (re * x.im) ) / denominator) };
}

ASSY::Complex ASSY::Complex::conjugate() const {
    return {re, -im };
}

ASSY::Complex ASSY::Complex::pow(int n) {
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
