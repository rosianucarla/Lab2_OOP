#include <iostream>
#include <assert.h>
#include "Complex.h"
#include "Rational.h"

int main() {
    Complex v[] = { Complex(3,4), Complex(1,2),Complex(3,1),Complex(1,1) }; // Reihe der Objekte vom Typ-Complex.

    assert(v[0].abs() == 5); //test
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
    for (int i = 0; i < n - 1; i++) { //sortare dupa valoare absoluta
        for (int j = i + 1; j < n; j++)
            if (v[i].abs() > v[j].abs()) {
             
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    }
    for (int i = 0; i < n; i++) { //afisarea dupa sortare
        //std::cout<<v[i].abs()<<" ";
        v[i].show_compl();
    }
    std::cout << "\n";

    Complex sum = Complex(0, 0); //Gesamtsumme der Reihe
    for (int i = 0; i < n; i++) {
        aux = sum.add(v[i]);
        sum.setreal(aux.getreal());
        sum.setimag(aux.getimag());
    }
    std::cout << sum.getreal() << " + " << sum.getimag() << "i" << "\n";
    v[1].show_compl();
    v[1].show_exp();
    std::cout << "\n";




    Rational r[] = { Rational(10,3),Rational(11,5) };///reihe typ rational

    Rational added = Rational(1, 1);
    added = r[0].add(r[1]);
    added.show();//test add
    std::cout << "\n";
    Rational multi = Rational(1, 1);///test mult
    multi = r[0].mul(r[1]);
    multi.show();

    std::cout << "\n";
    Rational quoti = Rational(1, 1);///test impartire
    quoti = r[0].quot(r[1]);
    quoti.show();

    return 0;
}
