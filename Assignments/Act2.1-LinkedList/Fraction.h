

// Carolina Vildósola Guzmán
// A01287373

#ifndef FRACTION_H
#define FRACTION_H


class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator = 0, int denominator = 1);
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int numerator);
    void setDenominator(int denominator);
};

#endif // FRACTION_H