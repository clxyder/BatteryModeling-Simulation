/*
Title:      Bisection Root Calculator
Name:       Carlos A. Wong
Course:     EEE5452
Due Date:   09/07/17

*/
#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return 3*exp(3*x)-exp(-1*pow(x,3)*log(3))+(1/3.0);
}
int main()
{
    double a, b, c, fa, fb, fc, product, eps = 1e-6;
    int itr = 0;
    
    cout << "Welcome to Bisection Root Calculator!\n";
    
    do
    {
        cout << "Initial Interval:\n";
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        product = f(a) * f(b);
        if(product > 0)
            cout << "Please enter different values for a and b.\n";
            
    }while(product > 0);

    while(fabs(a-b) >= eps && itr <= 30)
    {
        c = (a + b)/2.0;
        fa = f(a);
        fb = f(b);
        fc = f(c);
        product = fa * fc;
        
        if(product < 0)
        {
            b = c;
            fb = fc;
        }
        else if(product > 0)
        {
            a = c;
            fa = fc;
        }
        else if(fc == 0)
            break;
            
        itr++;
    }
    
    if( itr == 30)
        cout << "Maximum iterations reach, could not calculate root with desired accuracy.\n";
    cout << "Root value: " << c << " +- "<< eps << "\nNumber of Iterations: " << itr << "\n";

    return 0;
}