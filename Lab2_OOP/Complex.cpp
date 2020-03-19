#include "Complex.h"
#include <iostream>
#include <cmath>
#include <string.h>

//konstrukot
Complex::Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

////afiseaza a+bi
void Complex::show_compl() {
    std::cout << this->getreal() << " + " << this->getimag() << "i" << "\n";
}

//r*e^(ia)
void Complex::show_exp() {
    Complex* expo;
    double abs = this->abs();
    double teta = atan(this->getimag() / this->getreal());
    std::cout << abs << "e^i" << teta;

}
//addition
Complex Complex::add(Complex c) {
    c.imag = this->imag + c.imag;
    c.real = this->real + c.real;
    return c;
}

//multiplikation
Complex Complex::mul(Complex c) {
    double r = c.real * this->real - c.imag * this->imag;
    double i = this->real * c.imag + this->imag * c.real;
    c.real = r;
    c.imag = i;
    return c;
}

//division
Complex Complex::quot(Complex c) {
    c.imag = -c.imag;
    auto* zahler = new Complex(this->mul(c).real, this->mul(c).imag);
    double nenner = pow(c.real, 2) + pow(c.getimag(), 2);
    c.real = zahler->real / nenner;
    c.imag = zahler->imag / nenner;
    return c;
}

//valoarea abs
double Complex::abs() {
    //std::cout<<this->real<<" "<< this->imag<<"\n"
    return sqrt(pow(this->real, 2) + pow(this->imag, 2));
}

//getter
double Complex::getimag() {
    return this->imag;
}

//setter
void Complex::setimag(double imag) {
    this->imag = imag;
}

//getter
double Complex::getreal() {
    return real;
}

//setter
void Complex::setreal(double real) {
    this->real = real;
}

//forma polara
Complex Complex::compute_polar() {
    double abs = this->abs();
    double teta = atan(this->getimag() / this->getreal());
    //Complex *polar =
    //polar->setreal(abs*cos(teta));
    //polar->setimag(abs*sin(teta));
    return Complex(abs * cos(teta), abs * sin(teta));;
}