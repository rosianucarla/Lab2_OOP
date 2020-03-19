#include <string.h>
#include <string>
#include <iostream>

class Complex {

private:

    double real;
    double imag;
public:
    Complex(double real, double imag); //constructor
  
    double abs(); //valoare absoluta

    void setreal(double real); //seteaza partea reala

    double getreal(); //returneaza partea reala 

    void setimag(double imag); //seteaza partea imaginara

    double getimag(); //returneaza partea reala

    void show_compl(); //afiseaza a+bi

    Complex compute_polar(); //forma polara: r*(cos a + i* sin a)

    void show_exp(); //r*e^(ia)

    Complex add(Complex c); //addition

    Complex mul(Complex c);  //multiplikation

    Complex quot(Complex c); //division
};
