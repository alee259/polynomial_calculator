#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#define MAX_COUNT 100
using namespace std;


 /**
 * @class Polynomial
 * @brief A class to represent a polynomial.
 * 
 * The Polynomial class provides functionalities to create, copy, and perform
 * arithmetic operations on polynomial expressions.
 */
class Polynomial
{
public:
    Polynomial(); // POSTCONDITION: This polynomial has been created with all zero coefficients.
    Polynomial(double* coef, int degree); //contructor with parameters
    Polynomial(const Polynomial& poly); // copy constructor
    ~Polynomial(); // destructor
    // setters and getters
    void setDegree(int degree); 
    void setCoef(double* coef, int degree);
    int getDegree();
    double* getCoef();
    double getOneCoef(unsigned int exponent) const; 
    // POSTCONDITION: Returns coefficient at specified exponent of this polynomial
    Polynomial& operator=(const Polynomial& rightSide); // operator =
    Polynomial operator-(const Polynomial&); // binary operator -
    Polynomial operator+(const Polynomial&); // binary operator +
    Polynomial operator*(const Polynomial&); // binary operator *
    friend ostream& operator <<(ostream&, const Polynomial& p); // operator <<
    friend istream& operator >>(istream& ins, Polynomial& p); // operator >>
    double evaluate(double x) const; // POSTCONDITION: The return value is the value of this polynomial when evaluated at x.
    Polynomial integral() const; 
    // POSTCONDITION: The return value is the integral of this polynomial.
    Polynomial derivative() const;
    // POSTCONDITION: The return value is the derivative of this polynomial.
private:
    double* coef; // dynamic array of coefficients
    int degree; // degree of a polynomial
};

double convertFractionToDecimal(const string& fraction); // POSTCONDITION: The return value is the decimal equivalent of the fraction.