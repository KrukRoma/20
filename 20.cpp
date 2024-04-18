#include <iostream>
using namespace std;

class Fraction 
{
private:
    int numerator;   
    int denominator; 

    void simplify() 
    {
        int gcd_value = gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
    }

    int gcd(int a, int b) 
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) 
    {
        simplify(); 
    }

    Fraction operator+(const Fraction& other) const 
    {
        int common_denominator = denominator * other.denominator;
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        return Fraction(new_numerator, common_denominator);
    }

    Fraction operator-(const Fraction& other) const 
    {
        int common_denominator = denominator * other.denominator;
        int new_numerator = numerator * other.denominator - other.numerator * denominator;
        return Fraction(new_numerator, common_denominator);
    }

    Fraction operator*(const Fraction& other) const 
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    friend ostream& operator<<(ostream& os, const Fraction& fraction) 
    {
        os << fraction.numerator << '/' << fraction.denominator;
        return os;
    }
};

int main() 
{
    Fraction f1(3, 4);
    Fraction f2(2, 5);

    Fraction result1 = f1 + f2;
    Fraction result2 = f1 - f2;
    Fraction result3 = f1 * f2;
    Fraction result4 = f1 / f2;

    cout << "f1 + f2 = " << result1 << endl;
    cout << "f1 - f2 = " << result2 << endl;
    cout << "f1 * f2 = " << result3 << endl;
    cout << "f1 / f2 = " << result4 << endl;
}

