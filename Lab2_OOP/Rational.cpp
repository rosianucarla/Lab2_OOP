#include <iostream>
#include "rational.h"

///propr
int Rational::getzahler() {
    return this->zahler;
}

///propr
int Rational::getnenner() {
    return this->nenner;
}

///setter
void Rational::setzahler(int zahler) {
    this->zahler = zahler;
}

///setter
void Rational::setnenner(int nenner) {
    this->nenner = nenner;
}

///konstruktor
Rational::Rational(int zahler, int nenner) {
    this->zahler = zahler;
    this->nenner = nenner;
}

///afiseaza numarul rat
void Rational::show() {
    std::cout << this->zahler << "/" << this->nenner;
}

///adunarea a 2 nr rationale
Rational Rational::add(Rational r) {

    r.zahler = r.zahler * this->nenner + this->zahler * r.nenner;
    r.nenner = r.nenner * this->nenner;

    ///algoritm pt simplificarea functiei
    int i = 2;
    while (i < r.nenner and i < r.zahler) {
        if (r.nenner % i == 0 and r.zahler % i == 0)
        {
            r.nenner /= i;
            r.zahler /= i;
        }
        i++;
    }

    return r;
}

///inmultirea a 2 nr rat
Rational Rational::mul(Rational r) {

    r.zahler = r.zahler * this->zahler;
    r.nenner = r.nenner * this->nenner;

    ///algoritm pt simplificarea functiei
    int i = 2;
    while (i < r.nenner and i < r.zahler) {
        if (r.nenner % i == 0 and r.zahler % i == 0)
        {
            r.nenner /= i;
            r.zahler /= i;
        }
        i++;
    }

    return r;
}
///impartirea
Rational Rational::quot(Rational r) {
    int aux;
    aux = r.zahler;
    r.zahler = r.nenner;
    r.nenner = aux;
    return this->mul(r);
}