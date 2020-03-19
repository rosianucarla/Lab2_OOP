#include <iostream>
#include <assert.h>
#include "complex.h"
#include "rational.h"

int main() {
    Complex v[] = { Complex(3,4), Complex(1,2),Complex(3,1),Complex(1,1) };

    assert(v[0].abs() == 5);
    Complex add = v[0].add(v[1]);
    assert(add.getreal() == 4);
    assert(add.getimag() == 6);
    Complex mul = v[0].mul(v[1]);
    assert(mul.getreal() == -5);
    assert(mul.getimag() == 10);
    Complex quot = v[2].quot(v[3]);
    assert(quot.getreal() == 2);
    assert(quot.getimag() == -1);
    int n = sizeof(v) / 16;
    Complex aux = Complex(0, 0);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++)
            if (v[i].abs() > v[j].abs()) {
                /*
                aux.setreal(v[i].getreal());
                aux.setimag(v[i].getimag());
                v[i].setreal(v[j].getreal());
                v[i].setimag(v[j].getimag());
                v[j].setreal(aux.getreal());
                v[j].setimag(aux.getimag());*/
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    }
    for (int i = 0; i < n; i++) {
        //std::cout<<v[i].abs()<<" ";
        v[i].show_compl();
    }
    std::cout << "\n";
    Complex sum = Complex(0, 0);
    for (int i = 0; i < n; i++) {
        aux = sum.add(v[i]);
        sum.setreal(aux.getreal());
        sum.setimag(aux.getimag());
    }
    std::cout << sum.getreal() << " + " << sum.getimag() << "i" << "\n";
    v[1].show_compl();
    v[1].show_exp();
    std::cout << "\n";

    Rational r[] = { Rational(10,3),Rational(11,5) };

    Rational added = Rational(1, 1);
    added = r[0].add(r[1]);
    added.show();
    std::cout << "\n";
    Rational multi = Rational(1, 1);
    multi = r[0].mul(r[1]);
    multi.show();

    std::cout << "\n";
    Rational quoti = Rational(1, 1);
    quoti = r[0].quot(r[1]);
    quoti.show();

    return 0;
}
