#include "polynomialv2.cpp"
using namespace std;

int main()
{
    Polynomial p1; 
    Polynomial p2;
    cin >> p1;
    cin >> p2;
    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;;
    Polynomial add = p1 + p2;
    cout << "Addition: " << add << endl;
    Polynomial subtract = p1 - p2;
    cout << "Subtraction: " << subtract << endl;
    Polynomial multiply = p1 * p2;
    cout << "Multiplication: " << multiply << endl;
    cout << "Enter the nbumner to evaluate the polynomial: ";
    double x;
    cin >> x; 
    cout << "Evalutated: " << p1.evaluate(x) << endl;
    Polynomial derivitave = p1.derivative();
    cout << endl <<"Derivative: " << derivitave << endl;
    Polynomial integral = p1.integral();
    cout << "Integral: " << integral << endl;

    return 0;


}