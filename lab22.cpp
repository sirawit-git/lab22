#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{                
    public:
        double real;
        double imag;
        ComplexNumber(double,double);
        ComplexNumber operator+(const ComplexNumber &) const;
        ComplexNumber operator-(const ComplexNumber &) const;
        ComplexNumber operator*(const ComplexNumber &) const;
        ComplexNumber operator/(const ComplexNumber &) const;
        bool operator==(const ComplexNumber &) const;
        bool operator==(double) const;
        
        double abs() const;
        double angle() const;
        
        ComplexNumber operator+(double) const;
        ComplexNumber operator-(double) const;
        ComplexNumber operator*(double) const;
        ComplexNumber operator/(double) const;
        
        friend ComplexNumber operator+(double, const ComplexNumber &);
        friend ComplexNumber operator-(double, const ComplexNumber &);
        friend ComplexNumber operator*(double, const ComplexNumber &);
        friend ComplexNumber operator/(double, const ComplexNumber &);
        friend bool operator==(double, const ComplexNumber &);
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
    real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c) const {
    return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c) const {
    return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) const {
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) const {
    double denom = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / denom, (imag * c.real - real * c.imag) / denom);
}

bool ComplexNumber::operator==(const ComplexNumber &c) const {
    return real == c.real && imag == c.imag;
}

bool ComplexNumber::operator==(double d) const {
    return real == d && imag == 0;
}

bool operator==(double d, const ComplexNumber &c){
    return c == d;
}

double ComplexNumber::abs() const {
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle() const {
    return atan2(imag, real) * 180 / M_PI;
}

ComplexNumber ComplexNumber::operator+(double d) const {
    return ComplexNumber(real + d, imag);
}

ComplexNumber ComplexNumber::operator-(double d) const {
    return ComplexNumber(real - d, imag);
}

ComplexNumber ComplexNumber::operator*(double d) const {
    return ComplexNumber(real * d, imag * d);
}

ComplexNumber ComplexNumber::operator/(double d) const {
    return ComplexNumber(real / d, imag / d);
}

ComplexNumber operator+(double d, const ComplexNumber &c){
    return ComplexNumber(d + c.real, c.imag);
}

ComplexNumber operator-(double d, const ComplexNumber &c){
    return ComplexNumber(d - c.real, -c.imag);
}

ComplexNumber operator*(double d, const ComplexNumber &c){
    return ComplexNumber(d * c.real, d * c.imag);
}

ComplexNumber operator/(double d, const ComplexNumber &c){
    double denom = c.real * c.real + c.imag * c.imag;
    return ComplexNumber(d * c.real / denom, -d * c.imag / denom);
}

ostream& operator<<(ostream &os, const ComplexNumber &c) {
    if (c.real == 0 && c.imag == 0) return os << 0;
    if (c.imag == 0) return os << c.real;
    if (c.real == 0) return os << c.imag << "i";
    if (c.imag > 0) return os << c.real << "+" << c.imag << "i";
    return os << c.real << c.imag << "i";
}