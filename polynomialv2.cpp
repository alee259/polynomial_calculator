
#include "polynomialv2.h"
#include <iostream>
using namespace std;

/**
 * @brief Converts a fraction represented as a string to its decimal equivalent.
 * 
 * This function takes a fraction represented as a string and converts it to its decimal equivalent.
 * The fraction can be in the form of "numerator/denominator" or a single number.
 * 
 * @param fraction The fraction to be converted.
 * @return The decimal equivalent of the fraction.
 */
double convertFractionToDecimal(const string& fraction)
{
    size_t pos = fraction.find('/');
    if (pos != string::npos) {
        string numerator_str = fraction.substr(0, pos);
        string denominator_str = fraction.substr(pos + 1);
        double numerator = stod(numerator_str);
        double denominator = stod(denominator_str);
        return numerator / denominator;   
    }else{
        return stod(fraction);
    }
    
    return 0;
}

/**
 * @brief Default constructor for the Polynomial class.
 * 
 * Initializes a Polynomial object with default values.
 */

Polynomial::Polynomial(){
    degree = 1;
    coef = new double[degree];
    coef[0] = 0;
}


/**
 * @brief Constructs a Polynomial object with given coefficients and degree.
 * 
 * @param coef Pointer to an array of coefficients.
 * @param degree The degree of the polynomial.
 */
Polynomial::Polynomial(double* coef, int degree)
{
    this -> degree = degree;
    this -> coef = coef; 
}


/**
 * @brief Copy constructor for the Polynomial class.
 * 
 * Creates a new Polynomial object as a copy of an existing Polynomial object.
 * 
 * @param poly The Polynomial object to copy.
 */
Polynomial::Polynomial(const Polynomial& poly)
{
    degree = poly.degree;
    coef = new double[degree + 1];
    for (int i = 0; i < degree+1; i++)
    {
        coef[i] = poly.coef[i];
    }

} // copy constructor

/**
 * @brief Destructor for the Polynomial class.
 * 
 * Cleans up any dynamically allocated memory used by the Polynomial object.
 */
Polynomial:: ~Polynomial(){
    delete[] coef;
}


void Polynomial::setDegree(int degree)
{
    this -> degree = degree;
}
void Polynomial::setCoef(double* coef, int degree)
{
    for (int i = 0; i < degree+1; i++)
    {
        this -> coef[i] = coef[i];
    }
}

int Polynomial::getDegree(){return degree;}
double* Polynomial::getCoef(){return coef;}
double Polynomial::getOneCoef(unsigned int exponent) const
{
    return coef[exponent];
}

/**
 * @brief Evaluates the polynomial at a given value of x.
 * 
 * This function evaluates the polynomial at a given value of x and returns the result.
 * 
 * @param x The value of x to evaluate the polynomial at.
 * @return The result of evaluating the polynomial at x.
 */
double Polynomial::evaluate(double x) const
{
    double result = 0;
    for (int i = 0; i < degree+1; i++)
    {
        result += coef[i] * pow(x, i);
    }
    return result;
}

/**
 * @brief Returns the derivative of the polynomial.
 * 
 * This function returns a new Polynomial object representing the derivative of the current polynomial.
 * 
 * @return The derivative of the polynomial.
 */
Polynomial Polynomial::derivative() const
{
    double* temp = new double[degree];
    for (int i = 0; i < degree; i++)
    {
        temp[i] = coef[i+1] * (i+1);
    }
    Polynomial result(temp, degree-1);
    return result;
}

/**
 * @brief Returns the integral of the polynomial.
 * 
 * This function returns a new Polynomial object representing the integral of the current polynomial.
 * 
 * @return The integral of the polynomial.
 */
Polynomial Polynomial::integral() const
{
    double* temp = new double[degree+2];
    temp[0] = 0;
    for (int i = 0; i < degree+1; i++)
    {
        temp[i+1] = coef[i] / (i+1);
    }
    Polynomial result(temp, degree+1);
    return result;
}

/** * @brief Overloads the assignment operator for the Polynomial class. *  
 * 
 * * This function assigns the values of one Polynomial object to another.olynomial& *  
 * * @param rightSide The Polynomial object to assign from. 
 * * @return Polynomial& A reference to the assigned Polynomial object.nt i = 
 * 
 * */

Polynomial& Polynomial::operator=(const Polynomial& rightSide)
{
    delete[] coef;
    degree = rightSide.degree;
    coef = new double[degree+1];
    for (int i = 0; i < degree+1; i++)
    {
       coef[i] = rightSide.coef[i];
    }

    return *this;    
} // operator =


/**
 * @brief Overloads the addition operator for the Polynomial class.
 * 
 * This function adds two Polynomial objects and returns a new Polynomial object
 * representing the sum of the two polynomials.
 * 
 * @param p The Polynomial object to be added to the current Polynomial object.
 * @return Polynomial A new Polynomial object representing the sum of the two polynomials.
 */
Polynomial Polynomial::operator+(const Polynomial& p)
{
    int newDegree(0);
    int smallDegree(0);
    bool left_larger = false;
    if (degree > p.degree)
    {
        newDegree = degree;
        smallDegree = p.degree;
        left_larger = true;
    }else{
        newDegree = p.degree;
        smallDegree = degree;
        left_larger = false;
    }

    double* temp = new double[newDegree+1];
    if (left_larger)
    {
        copy(coef, coef + degree + 1, temp);
    }else{
        copy(p.coef, p.coef + p.degree + 1, temp);
    }
    

    for (int i = 0; i <= smallDegree; i++)
    {
        temp[i] = coef[i] + p.coef[i];
                
    }
    
    Polynomial result(temp, newDegree);
    return result;
            

}

/**
 * @brief Overloads the subtraction operator for the Polynomial class.
 * 
 * This function subtracts two Polynomial objects and returns a new Polynomial object
 * representing the difference of the two polynomials.
 * 
 * @param p The Polynomial object to be subtracted from the current Polynomial object.
 * @return Polynomial A new Polynomial object representing the difference of the two polynomials.
 */
Polynomial Polynomial::operator-(const Polynomial& p)
{
    int newDegree(0);
    int smallDegree(0);
    bool left_larger = false;
    if (degree > p.degree)
    {
        newDegree = degree;
        smallDegree = p.degree;
        left_larger = true;
    }else{
        newDegree = p.degree;
        smallDegree = degree;
        left_larger = false;
    }

    double* temp = new double[newDegree+1];
    if (left_larger)
    {
        copy(coef, coef + degree + 1, temp);
    }else{
        copy(p.coef, p.coef + p.degree + 1, temp);
    }
    

    for (int i = 0; i <= smallDegree; i++)
    {
        temp[i] = coef[i] - p.coef[i];
                
    }
    
    Polynomial result(temp, newDegree);
    return result;
}

/**
 * @brief Overloads the multiplication operator for the Polynomial class.
 * 
 * This function multiplies two Polynomial objects and returns a new Polynomial object
 * representing the product of the two polynomials.
 * 
 * @param p The Polynomial object to be multiplied with the current Polynomial object.
 * @return Polynomial A new Polynomial object representing the product of the two polynomials.
 */
Polynomial Polynomial::operator*(const Polynomial& p)
{
    int newDegree = degree + p.degree;
    double* temp = new double[newDegree+1];
    for (int i = 0; i < newDegree+1; i++)
    {
        temp[i] = 0;
    }
    
    for (int i = 0; i < degree+1; i++)
    {
        for (int j = 0; j < p.degree+1; j++)
        {
            temp[i+j] += coef[i] * p.coef[j];
        }
    }
    Polynomial result(temp, newDegree);
    return result;
}

  /** * @brief Overloads the stream insertion operator for the Polynomial class. *  
   * * This function allows a Polynomial object to be output to an output stream. *  
   * * @param os The output stream to write to. * @param p The Polynomial object to output. 
   * * @return ostream& The output stream. *//**
   * */

ostream& operator<<(ostream& os, const Polynomial& p)
{
    bool firstTerm = true; // Flag to handle the '+' sign correctly
    
    for (int i = p.degree; i >= 0; i--) {
        if (p.coef[i] != 0) {
            // Print '+' if it's not the first term and the term is not x^0
            if (!firstTerm) {
                cout << " + ";
            }
            
            // Print the coefficient and term
            if (i == 0) {
                cout << p.coef[i]; // Just print the coefficient for x^0
            } else if (p.coef[i] == 1) {
                cout << "x^" << i; // Print x^i if coefficient is 1
            } else if (p.coef[i] == -1) {
                cout << "-x^" << i; // Print -x^i if coefficient is -1
            } else {
                cout << p.coef[i] << "x^" << i; // Print coefficient and x^i
            }
            
            firstTerm = false; // No longer the first term
        }
    }
    
    if (firstTerm) {
        cout << "0"; // Handle the case where the polynomial is zero
    }
    
    cout << endl; // New line after polynomial
    return os;

    
}

/**
 * @brief Overloads the stream extraction operator for the Polynomial class.
 * 
 * This function allows a Polynomial object to be input from an input stream.
 * 
 * @param ins The input stream to read from.
 * @param p The Polynomial object to input to.
 * @return istream& The input stream.
 */
istream& operator >>(istream& ins, Polynomial& p)
{
    cout << "Enter Polynomial: ";
    double* temp_coef = new double[MAX_COUNT];
    for (int i = 0; i < MAX_COUNT; i++) {
        temp_coef[i] = 0;
        
    }

    string input;
    getline(cin, input);
    stringstream ss(input);
    string term;

    bool first_exponent_found = false;
    int first_exponent = -1;
    

    while (ss >> term) {
        size_t pos = term.find('^');        
        if (pos != string::npos) {
            string base_str = term.substr(0, pos);
            string exponent_str = term.substr(pos + 1);
                
            double base = convertFractionToDecimal(base_str);
            int exponent = stoi(exponent_str);

            if (exponent >= 0 && exponent < MAX_COUNT) {
                temp_coef[exponent] = base;
            } else {
                cout << "Exponent " << exponent << " out of bounds!" << endl;
            }

            // Store the first exponent found
            if (!first_exponent_found) {
                first_exponent = exponent;
                first_exponent_found = true;
                p.degree = first_exponent;
            }
        } else {
            cout << "No '^' found in term: " << term << endl;
        }
    }
    
    delete[] p.coef;
    p.coef = new double[p.degree + 1];
    for (int i = 0; i < p.degree + 1; i++) {
        p.coef[i] = temp_coef[i];
    }

    delete[] temp_coef; //delete temp array memory
    
    return ins;

}
