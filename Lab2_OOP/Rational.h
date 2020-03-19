class Rational {
private:
    int zahler{};
    int nenner{};

public:
    Rational(int zahler, int nenner); //konstruktr
    int getzahler();///return zahler
    int getnenner();///return nenner
    void setzahler(int zahler);///seteaza zahler
    void setnenner(int nenner);///seteaza nenner
    void show();///afiseaza nr

    Rational add(Rational r); ///addition

    Rational mul(Rational r);///multiplikation

    Rational quot(Rational r);///impartire
};
